package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

type Meeting struct {
	start, end int64
}

func main() {
	defer writer.Flush()
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	meetings := make([]Meeting, N)

	for i := 0; i < N; i++ {
		scanner.Scan()
		parts := strings.Fields(scanner.Text())
		s, _ := strconv.ParseInt(parts[0], 10, 64)
		e, _ := strconv.ParseInt(parts[1], 10, 64)
		meetings[i] = Meeting{s, e}
	}

	sort.Slice(meetings, func(i, j int) bool {
		if meetings[i].end == meetings[j].end {
			return meetings[i].start < meetings[j].start
		}
		return meetings[i].end < meetings[j].end
	})

	var count int
	var lastEnd int64 = 0

	for _, m := range meetings {
		if m.start >= lastEnd {
			count++
			lastEnd = m.end
		}
	}

	fmt.Fprintln(writer, count)
}
