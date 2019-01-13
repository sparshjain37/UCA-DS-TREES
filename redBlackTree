package com.uca.tree;

public class RBT<K extends Comparable<K>, V> {
	private Node root;
	private final boolean BLACK = true;
	private final boolean RED = false;

	public void insert(K key, V val) {
		root = insert(root, key, val);
		root.color = BLACK;
	}

	public int height() {
		return height(root);
	}

	private int height(Node n) {
		if (n == null)
			return 0;
		return 1 + Math.max(height(n.left), height(n.right));
	}

	private boolean colorOf(Node n) {
		return n == null ? BLACK : n.color;
	}

	private Node insert(Node n, K key, V val) {
		if (n == null)
			return new Node(key, val);
		int cmp = key.compareTo(n.key);
		if (cmp > 0)
			n.right = insert(n.right, key, val);
		else if (cmp < 0)
			n.left = insert(n.left, key, val);
		else
			n.val = val;
		n.N = 1 + sizeOf(n.left) + sizeOf(n.right);

		if (colorOf(n.right) == RED && colorOf(n.left) == BLACK) {
			n = leftRotate(n);
		}
		if (colorOf(n.left) == RED && colorOf(n.left.left) == RED) {
			n = rightRotate(n);
		}
		if (colorOf(n.left) == RED && colorOf(n.right) == RED) {
			n = swapColors(n);
		}
		return n;
	}

	private Node leftRotate(Node n) {
		Node x = n.right;
		n.right = x.left;
		x.left = n;
		x.color = n.color;
		n.color = RED;
		return x;
	}

	private Node rightRotate(Node n) {
		Node x = n.left;
		n.left = x.right;
		x.right = n;
		x.color = n.color;
		n.color = RED;
		return x;
	}

	private Node swapColors(Node n) {
		n.left.color = n.color;
		n.right.color = n.color;
		n.color = RED;
		return n;
	}

	public V search(K key) {
		Node n = search(root, key);
		return n == null ? null : n.val;
	}

	private Node search(Node n, K key) {
		if (n == null)
			return null;
		int cmp = key.compareTo(n.key);
		if (cmp > 0)
			return search(n.right, key);
		if (cmp < 0)
			return search(n.left, key);
		return n;
	}

	private int sizeOf(Node n) {
		return n == null ? 0 : n.N;
	}

	private class Node {
		private K key;
		private V val;
		private boolean color;
		private Node left = null;
		private Node right = null;
		private int N;

		public Node(K key, V val) {
			this.key = key;
			this.val = val;
			this.N = 1;
			this.color = RED;
		}
	}

}
