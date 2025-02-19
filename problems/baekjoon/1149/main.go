package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

type Color uint

const (
	Red Color = iota
	Green
	Blue
)

type PriceMap [][3]int

func NewPriceMap(s *bufio.Scanner) PriceMap {
	var priceMap PriceMap
	var length int
	if s.Scan() {
		length, _ = strconv.Atoi(s.Text())
		priceMap = make(PriceMap, length)
	}

	for i := 0; i < length; i++ {
		priceMap[i] = [3]int{}
		if s.Scan() {
			for j, price := range strings.Fields(s.Text()) {
				priceMap[i][j], _ = strconv.Atoi(price)
			}
		}
	}

	return priceMap
}

type ColorNode struct {
	color        Color
	price, depth int
	left, right  *ColorNode
}

func NewColorNode(color Color, price, depth int) *ColorNode {
	return &ColorNode{
		color: color,
		price: price,
		depth: depth,
	}
}

func buildColorTree(root *ColorNode, priceMap PriceMap) {
	if root.depth == len(priceMap)-1 {
		return
	}

	nextDepth := root.depth + 1
	switch root.color {
	case Red:
		root.left = NewColorNode(Green, root.price+priceMap[nextDepth][Green], nextDepth)
		root.right = NewColorNode(Blue, root.price+priceMap[nextDepth][Blue], nextDepth)
	case Green:
		root.left = NewColorNode(Red, root.price+priceMap[nextDepth][Red], nextDepth)
		root.right = NewColorNode(Blue, root.price+priceMap[nextDepth][Blue], nextDepth)
	case Blue:
		root.left = NewColorNode(Red, root.price+priceMap[nextDepth][Red], nextDepth)
		root.right = NewColorNode(Green, root.price+priceMap[nextDepth][Green], nextDepth)
	}

	buildColorTree(root.left, priceMap)
	buildColorTree(root.right, priceMap)
}

func findLowestPrice(root *ColorNode) int {
	if root.left == nil && root.right == nil {
		return root.price
	}

	left := findLowestPrice(root.left)
	right := findLowestPrice(root.right)

	if left < right {
		return left
	}
	return right
}

func main() {
	defer writer.Flush()
	priceMap := NewPriceMap(scanner)

	trees := [3]*ColorNode{
		NewColorNode(Red, priceMap[0][Red], 0),
		NewColorNode(Green, priceMap[0][Green], 0),
		NewColorNode(Blue, priceMap[0][Blue], 0),
	}

	lowest := math.MaxInt
	for _, tree := range trees {
		buildColorTree(tree, priceMap)
		if price := findLowestPrice(tree); lowest > price {
			lowest = price
		}
	}

	fmt.Fprintln(writer, lowest)
}
