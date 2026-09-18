#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll gId = 0;
ll kingId = 1;

struct node {
	struct node *parent;
	vector<struct node*> children;
	bool alive;
	ll id;
};

vector<node*> nodes;

void createNode(struct node *parent) {
	struct node *temp = new node;
	temp->parent = parent;
	temp->alive = true;
	temp->id = ++gId;

	if (parent != nullptr) {
		parent->children.push_back(temp);
	}

	nodes.push_back(temp);
}

node* traversal(node* root) {
	for (node* c : root->children) {
		if (c->alive) {
			return c;
		}

		if (struct node* t = traversal(c); t != nullptr) {
			return t;
		}
	}

	return nullptr;
}

struct node* findSuccessor(struct node *root) {
	struct node *suc = traversal(root);
	if (suc != nullptr) {
		return suc;
	};

	// The questions says that a new successor will always exist
	// Ugly but should work
	while (true) {
		struct node* p = root->parent;
		size_t i = 0;
		while (i < p->children.size() && p->children[i] != root) {
			i++;
		}

		for (i = i + 1; i < p->children.size(); i++) {       // only later siblings
			struct node* c = p->children[i];
			if (c->alive)
				return c;

			if (struct node* t = traversal(c))
				return t;
		}

		root = root->parent;
	}
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll q, t, x;
	cin >> q;

	struct node *root = new node{nullptr, vector<struct node*>(), true, ++gId};
	nodes.assign(2, nullptr);
	nodes[1] = root;

	for (ll i = 0; i < q; i++) {
		cin >> t >> x;

		if (t == 1) {
			createNode(nodes[x]);
		}
		else {
			struct node *dead = nodes[x];
			dead->alive = false;

			if (dead->id == kingId) {
				kingId = findSuccessor(dead)->id;
			}

			cout << kingId << '\n';
		}
	}
}

