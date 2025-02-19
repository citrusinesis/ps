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

	masks = [4]Cursor{
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0},
	}
)

type Cursor = [2]int

type Maze struct {
	height  int
	width   int
	maze    [][]bool
	history [][]int
}

func NewMaze(scanner *bufio.Scanner) *Maze {
	scanner.Scan()
	sizeFields := strings.Fields(scanner.Text())

	height, err := strconv.Atoi(sizeFields[0])
	if err != nil {
		fmt.Println("Error parsing height:", err)
	}
	width, err := strconv.Atoi(sizeFields[1])
	if err != nil {
		fmt.Println("Error parsing width:", err)
	}

	maze := make([][]bool, height)
	for i := 0; i < height; i++ {
		maze[i] = make([]bool, width)
		scanner.Scan()
		line := scanner.Text()
		for j, field := range strings.Split(line, "") {
			if field == "1" {
				maze[i][j] = true
			} else {
				maze[i][j] = false
			}
		}
	}

	history := make([][]int, height)
	for i := range history {
		history[i] = make([]int, width)
	}
	history[0][0] = 1

	return &Maze{
		height:  height,
		width:   width,
		maze:    maze,
		history: history,
	}
}

//func solve(maze *Maze) int {
//	queue := []Cursor{{0, 0}}
//
//	for len(queue) > 0 {
//		cur := queue[0]
//		queue = queue[1:]
//
//		curDist := maze.history[cur[0]][cur[1]]
//
//		for _, mask := range masks {
//			next := Cursor{cur[0] + mask[0], cur[1] + mask[1]}
//
//			if next[0] >= 0 && next[0] < maze.height &&
//				next[1] >= 0 && next[1] < maze.width &&
//				maze.maze[next[0]][next[1]] &&
//				maze.history[next[0]][next[1]] == 0 {
//
//				maze.history[next[0]][next[1]] = curDist + 1
//				queue = append(queue, next)
//			}
//		}
//	}
//
//	return maze.history[maze.height-1][maze.width-1]
//}

func solve(maze *Maze) int {
	queue := make(chan Cursor, maze.height*maze.width)
	queue <- Cursor{0, 0}

	for len(queue) > 0 {
		cur := <-queue
		curDist := maze.history[cur[0]][cur[1]]

		if cur[0] == maze.height-1 && cur[1] == maze.width-1 {
			return curDist
		}

		for _, mask := range masks {
			next := Cursor{cur[0] + mask[0], cur[1] + mask[1]}
			if next[0] >= 0 && next[0] < maze.height &&
				next[1] >= 0 && next[1] < maze.width &&
				maze.maze[next[0]][next[1]] &&
				maze.history[next[0]][next[1]] == 0 {
				maze.history[next[0]][next[1]] = curDist + 1
				queue <- next
			}
		}
	}

	return 0
}

func main() {
	maze := NewMaze(scanner)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fprint(writer, solve(maze))
	writer.Flush()
}
