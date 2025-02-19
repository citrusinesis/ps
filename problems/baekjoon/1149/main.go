package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

const (
	Red = iota
	Green
	Blue
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	defer writer.Flush()

	scanner.Scan()
	length, _ := strconv.Atoi(scanner.Text())
	costs := make([][3]int, length)
	for i := 0; i < length; i++ {
		scanner.Scan()
		fields := strings.Fields(scanner.Text())
		for j := 0; j < 3; j++ {
			costs[i][j], _ = strconv.Atoi(fields[j])
		}
	}

	dp := make([][3]int, length)
	dp[0] = costs[0]

	for depth := 1; depth < length; depth++ {
		dp[depth][Red] = costs[depth][Red] + min(dp[depth-1][Green], dp[depth-1][Blue])
		dp[depth][Green] = costs[depth][Green] + min(dp[depth-1][Red], dp[depth-1][Blue])
		dp[depth][Blue] = costs[depth][Blue] + min(dp[depth-1][Red], dp[depth-1][Green])
	}

	result := min(dp[length-1][Red], min(dp[length-1][Green], dp[length-1][Blue]))
	fmt.Fprintln(writer, result)
}
