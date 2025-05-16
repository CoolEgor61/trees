#include "gtest.h"
#include "trees.h"

TEST(AVLTree, can_create_AVLTree)
{
	ASSERT_NO_THROW(AVLTree<int> a);
}

TEST(AVLTree, can_insert_in_AVL_tree)
{
	ASSERT_NO_THROW(AVLTree<int> a);
	AVLTree<int> a;
	ASSERT_NO_THROW(a.insertNode(1, 21));
	EXPECT_EQ(a.root->key, 1);
	EXPECT_EQ(a.root->data, 21);
}

TEST(AVLTree, can_left_rotate_in_AVL_tree)
{
	ASSERT_NO_THROW(AVLTree<int> a);
	AVLTree<int> a;
	a.insertNode(1, 21);
	a.insertNode(2, 22);
	a.insertNode(3, 23);
	EXPECT_EQ(a.root->key, 2);
}

TEST(AVLTree, can_right_rotate_in_AVL_tree)
{
	ASSERT_NO_THROW(AVLTree<int> a);
	AVLTree<int> a;
	a.insertNode(3, 23);
	a.insertNode(2, 22);
	a.insertNode(1, 21);
	EXPECT_EQ(a.root->key, 2);
}

TEST(AVLTree, can_find_in_AVL_tree)
{
	ASSERT_NO_THROW(AVLTree<int> a);
	AVLTree<int> a;
	a.insertNode(1, 21);
	a.insertNode(2, 22);
	a.insertNode(3, 23);
	AVLNode<int>* tmp = a.findNode(3);
	EXPECT_EQ(tmp->key, std::size_t(3));
	EXPECT_EQ(tmp->data, 23);
}

TEST(AVLTree, can_delete_in_AVL_tree)
{
	ASSERT_NO_THROW(AVLTree<int> a);
	AVLTree<int> a;
	a.insertNode(1, 21);
	a.insertNode(2, 22);
	a.insertNode(3, 23);
	a.deleteNode(2);
	AVLNode<int>* tmp = a.findNode(2);
	int f = 0;
	if (tmp == NULL) f = 1;
	EXPECT_EQ(f, 1);
}