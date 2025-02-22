package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

var dp [10001]int

func main() {
	defer writer.Flush()

	var N int
	if scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
	}

	dp[1], dp[2] = 1, 2

	for i := 3; i <= N; i++ {
		dp[i] = (dp[i-1] + dp[i-2]) % 10007
	}

	fmt.Fprintln(writer, dp[N])
}
