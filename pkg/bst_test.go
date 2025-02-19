package pkg

import "testing"

func equalSlice[T ordered](a, b []T) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func inorderSlice[T ordered](node *BSTNode[T]) []T {
	var res []T
	inorder(node, &res)
	return res
}

func treeHeight[T ordered](node *BSTNode[T]) int {
	if node == nil {
		return 0
	}
	leftH := treeHeight(node.Left)
	rightH := treeHeight(node.Right)
	if leftH > rightH {
		return leftH + 1
	}
	return rightH + 1
}

func TestInsert(t *testing.T) {
	bst := NewBST(10)
	bst.Insert(5)
	bst.Insert(15)
	bst.Insert(3)
	bst.Insert(7)
	bst.Insert(12)
	bst.Insert(20)

	expected := []int{3, 5, 7, 10, 12, 15, 20}
	result := inorderSlice(bst.root)
	if !equalSlice(result, expected) {
		t.Errorf("Insert: expected inorder %v, got %v", expected, result)
	}
}

func TestDelete(t *testing.T) {
	bst := NewBST(10)
	bst.Insert(5)
	bst.Insert(15)
	bst.Insert(3)
	bst.Insert(7)
	bst.Insert(12)
	bst.Insert(20)

	bst.Delete(3)
	expected := []int{5, 7, 10, 12, 15, 20}
	result := inorderSlice(bst.root)
	if !equalSlice(result, expected) {
		t.Errorf("Delete leaf: expected inorder %v, got %v", expected, result)
	}

	bst.Delete(5)
	expected = []int{7, 10, 12, 15, 20}
	result = inorderSlice(bst.root)
	if !equalSlice(result, expected) {
		t.Errorf("Delete one child: expected inorder %v, got %v", expected, result)
	}

	bst.Delete(15)
	expected = []int{7, 10, 12, 20}
	result = inorderSlice(bst.root)
	if !equalSlice(result, expected) {
		t.Errorf("Delete two children: expected inorder %v, got %v", expected, result)
	}
}

func TestShake(t *testing.T) {
	bst := NewBST(1)
	for i := 2; i <= 7; i++ {
		bst.Insert(i)
	}
	hBefore := treeHeight(bst.root)
	if hBefore != 7 {
		t.Errorf("Shake: expected height before shake to be 7, got %d", hBefore)
	}

	bst.Shake()
	hAfter := treeHeight(bst.root)
	if hAfter > 3 {
		t.Errorf("Shake: expected height after shake to be <= 3, got %d", hAfter)
	}

	expected := []int{1, 2, 3, 4, 5, 6, 7}
	result := inorderSlice(bst.root)
	if !equalSlice(result, expected) {
		t.Errorf("Shake: expected inorder %v, got %v", expected, result)
	}
}
