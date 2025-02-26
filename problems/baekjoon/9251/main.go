package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

func main() {
	defer writer.Flush()

	var S1, S2 string
	if scanner.Scan() {
		S1 = scanner.Text()
	}
	if scanner.Scan() {
		S2 = scanner.Text()
	}

	dp := make([][]int, len(S1)+1)
	for i := range dp {
		dp[i] = make([]int, len(S2)+1)
	}

	for i := 1; i < len(dp); i++ {
		for j := 1; j < len(dp[0]); j++ {
			if S1[i-1] == S2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j])
			}
		}
	}

	fmt.Fprintln(writer, dp[len(dp)-1][len(dp[0])-1])
}
