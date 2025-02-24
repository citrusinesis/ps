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

type Node struct {
	name string
	next []*Node
}

func writeName(sb *strings.Builder, node *Node) {
	sb.WriteString(node.name)
	for _, next := range node.next {
		writeName(sb, next)
	}
}

func main() {
	defer writer.Flush()

	var N int
	if scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
	}

	var univs []*Node
	for i := 0; i < N; i++ {
		if scanner.Scan() {
			univs = append(univs, &Node{scanner.Text(), []*Node{}})
		}
	}

	var to, from int
	for i := 1; i < N; i++ {
		if scanner.Scan() {
			input := strings.Fields(scanner.Text())
			to, _ = strconv.Atoi(input[0])
			from, _ = strconv.Atoi(input[1])

			to, from = to-1, from-1
		}

		univs[to].next = append(univs[to].next, univs[from])
	}

	var sb strings.Builder
	writeName(&sb, univs[to])
	fmt.Fprintln(writer, sb.String())
}
