package pkg

import "cmp"

type ordered = cmp.Ordered

type BSTNode[T ordered] struct {
	Value T
	Left  *BSTNode[T]
	Right *BSTNode[T]
}

type BST[T ordered] struct {
	root *BSTNode[T]
}

func NewBST[T ordered](value T) *BST[T] {
	return &BST[T]{root: &BSTNode[T]{Value: value}}
}

func (bst *BST[T]) Insert(value T) {
	bst.root = insertNode(bst.root, value)
}

func insertNode[T ordered](node *BSTNode[T], value T) *BSTNode[T] {
	if node == nil {
		return &BSTNode[T]{Value: value}
	}
	if value < node.Value {
		node.Left = insertNode(node.Left, value)
	} else {
		node.Right = insertNode(node.Right, value)
	}
	return node
}

func (bst *BST[T]) Delete(value T) {
	bst.root = deleteNode(bst.root, value)
}

func deleteNode[T ordered](node *BSTNode[T], value T) *BSTNode[T] {
	if node == nil {
		return nil
	}
	if value < node.Value {
		node.Left = deleteNode(node.Left, value)
	} else if value > node.Value {
		node.Right = deleteNode(node.Right, value)
	} else {
		if node.Left == nil {
			return node.Right
		} else if node.Right == nil {
			return node.Left
		}
		minRight := findMin(node.Right)
		node.Value = minRight.Value
		node.Right = deleteNode(node.Right, minRight.Value)
	}
	return node
}

func findMin[T ordered](node *BSTNode[T]) *BSTNode[T] {
	for node.Left != nil {
		node = node.Left
	}
	return node
}

func (bst *BST[T]) Shake() {
	var values []T
	inorder(bst.root, &values)
	bst.root = buildBalancedBST(values, 0, len(values)-1)
}

func inorder[T ordered](node *BSTNode[T], values *[]T) {
	if node == nil {
		return
	}
	inorder(node.Left, values)
	*values = append(*values, node.Value)
	inorder(node.Right, values)
}

func buildBalancedBST[T ordered](values []T, start, end int) *BSTNode[T] {
	if start > end {
		return nil
	}
	mid := (start + end) / 2
	node := &BSTNode[T]{Value: values[mid]}
	node.Left = buildBalancedBST[T](values, start, mid-1)
	node.Right = buildBalancedBST[T](values, mid+1, end)
	return node
}
