package pkg

type BinaryTreeNode[T any] struct {
	Value T
	Left  *BinaryTreeNode[T]
	Right *BinaryTreeNode[T]
}

func NewBinaryTree[T any](value T) *BinaryTreeNode[T] {
	return &BinaryTreeNode[T]{Value: value}
}

func (node *BinaryTreeNode[T]) InsertLeft(value T) *BinaryTreeNode[T] {
	node.Left = NewBinaryTree(value)
	return node.Left
}

func (node *BinaryTreeNode[T]) InsertRight(value T) *BinaryTreeNode[T] {
	node.Right = NewBinaryTree(value)
	return node.Right
}

func PreOrder[T any](node *BinaryTreeNode[T], f func(value T)) {
	if node == nil {
		return
	}
	f(node.Value)
	PreOrder(node.Left, f)
	PreOrder(node.Right, f)
}

func InOrder[T any](node *BinaryTreeNode[T], f func(value T)) {
	if node == nil {
		return
	}
	InOrder(node.Left, f)
	f(node.Value)
	InOrder(node.Right, f)
}

func PostOrder[T any](node *BinaryTreeNode[T], f func(value T)) {
	if node == nil {
		return
	}
	PostOrder(node.Left, f)
	PostOrder(node.Right, f)
	f(node.Value)
}
