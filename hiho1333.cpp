#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;

struct Node {
    int id, val, sz, add;
    ll sum;
    Node *l, *r, *p;
    Node(int _id, int _val) :id(_id), val(_val), sz(1), add(0), sum(val),l(NULL),r(NULL),p(NULL) {}
};
Node *root;
void out() {
    printf("-----------------BEGIN-----------------------\n");
    queue<Node*> q, p;
    if (!root) return;
    q.push(root);
    while (!q.empty()) {
        Node*node = q.front(); q.pop();
        printf("%d-%d-%lld-%d ", node->id, node->val, node->sum, node->sz);//id,val,sum,sz
        if (node->l) p.push(node->l);
        if (node->r) p.push(node->r);
        if (q.empty()) {
            printf("\n");
            while (!p.empty()) {
                q.push(p.front()); p.pop();
            }
        }
    }
    printf("-----------------END-----------------------\n");
}
void pushDown(Node *node) {
    if (node->l){
        node->l->sum += node->l->sz*(ll)node->add;
        node->l->val += node->add;
        node->l->add += node->add;
    }
    if (node->r) {
        node->r->sum += node->r->sz*(ll)node->add;
        node->r->val += node->add;
        node->r->add += node->add;
    }
    node->add = 0;
}
//调用前需要保证node没有懒惰标记
void update(Node*node) {
    node->sum = node->val;
    node->sz = 1;
    if (node->l) {
        node->sum += node->l->sum;
        node->sz += node->l->sz;
    }
    if (node->r) {
        node->sum += node->r->sum;
        node->sz += node->r->sz;
    }
}
void rotateLeft(Node *node) {
    Node *child = node->r, *p = node->p;
    pushDown(node);
    pushDown(child);
    node->r = child->l;
    if (child->l) child->l->p = node;
    child->l = node;
    node->p = child;
    child->p = p;
    if (!p) {
        root = child;
    }else {
        if (p->l && p->l == node) p->l = child;
        else p->r = child;
    }
    update(node);
    update(child);
}
void rotateRight(Node *node) {
    Node *child = node->l, *p = node->p;
    pushDown(node);
    pushDown(child);
    node->l = child->r;
    if (child->r) child->r->p = node;
    child->r = node;
    node->p = child;
    child->p = p;
    if (!p) {
        root = child;
    }else {
        if (p->l && p->l == node) p->l = child;
        else p->r = child;
    }
    update(node);
    update(child);
}
void splay(Node *node, Node *root) {
    Node *p, *g;
    while ((p = node->p) != root && (g = p->p) != root) {
        if (g->l && g->l == p) {
            if (p->l && p->l == node) {
                rotateRight(g);
                rotateRight(p);
            } else {
                rotateLeft(p);
                rotateRight(g);
            }
        }else {
            if (p->l && p->l == node) {
                rotateRight(p);
                rotateLeft(g);
            } else {
                rotateLeft(g);
                rotateLeft(p);
            }
        }
    }
    if (p != root) {
        if (p->l && p->l == node) {
            rotateRight(p);
        } else {
            rotateLeft(p);
        }
    }
}
//调用时root不能为NULL
void search(int id) {
    if (root->id == id) return;
    Node *node = root;
    while (true) {
        if (id < node->id) {
            if (!node->l) break;
            node = node->l;
            if (node->id == id) break;
        } else {
            if (!node->r) break;
            node = node->r;
            if (node->id == id) break;
        }
    }
    splay(node, NULL);
}
void insert(int id,int val) {
    if (!root) {
        root = new Node(id, val);
        return;
    }
    search(id);
    if (root->id == id) return;
    Node *node = new Node(id, val);
    pushDown(root);
    if (id < root->id) {
        node->l = root->l;
        if(root->l) root->l->p = node;
        root->l = NULL;
        node->r = root;
    } else {
        node->r = root->r;
        if (root->r) root->r->p = node;
        root->r = NULL;
        node->l = root;
    }
    root->p = node;
    update(root);
    update(node);
    root = node;
}
//调用时root不能为NULL
Node* getLess(int k) {
    search(k);
    if (root->id < k) return root;
    Node *node = root->l;
    if (!node) return NULL;
    while (node->r) node = node->r;
    return node;
}
//调用时root不能为NULL
Node* getGreater(int k) {
    search(k);
    if (root->id > k) return root;
    Node *node = root->r;
    if (!node) return NULL;
    while (node->l) node = node->l;
    return node;
}
void del(int a, int b) {
    if (!root) return;
    Node *pre = getLess(a), *next = getGreater(b);
    if (pre && next) {
        splay(pre, NULL);
        splay(next, pre);
        next->l = NULL;
        update(next);
        update(pre);
    } else if (pre) {
        splay(pre, NULL);
        pre->r = NULL;
        update(pre);
    } else if (next) {
        splay(next, NULL);
        next->l = NULL;
        update(next);
    } else {
        root = NULL;
    }
}
//保证[a,b]至少有一个成员，so root也不为空
ll query(int a, int b) {
    Node *pre = getLess(a), *next = getGreater(b);
    if (pre && next) {
        splay(pre, NULL);
        splay(next, pre);
        pushDown(pre);
        pushDown(next);
        return next->l->sum;
    } else if (pre) {
        splay(pre, NULL);
        pushDown(pre);
        return pre->r->sum;
    } else if (next) {
        splay(next, NULL);
        pushDown(next);
        return next->l->sum;
    } else {
        return root->sum;
    }
}
void mark(int a, int b,int d) {
    if (!root) return;
    Node *pre = getLess(a), *next = getGreater(b);
    if (pre && next) {
        splay(pre, NULL);
        splay(next, pre);
        if (next->l) {
            pushDown(pre);
            pushDown(next);
            next->l->add += d;
            next->l->sum += next->l->sz*(ll)d;
            next->l->val += d;
            update(next);
            update(pre);
        }
    } else if (pre) {
        splay(pre, NULL);
        if (pre->r) {
            pushDown(pre);
            pre->r->add += d;
            pre->r->val += d;
            pre->r->sum += pre->r->sz*(ll)d;
            update(pre);
        }
    } else if (next) {
        splay(next, NULL);
        if (next->l) {
            pushDown(next);
            next->l->add += d;
            next->l->val += d;
            next->l->sum += next->l->sz*(ll)d;
            update(next);
        }
    } else {
        pushDown(root);
        root->add += d;
        root->val += d;
        root->sum += root->sz*(ll)d;
        update(root);
    }
}
int main() {
    freopen("data.txt","r",stdin);
    int n;
    cin >> n;
    while (n--) {
        char op;
        int id, val, a, b, d;
        cin >> op;
        if (op == 'I') {
            cin >> id >> val;
            insert(id, val);
            //out();
        } else if (op == 'Q') {
            cin >> a >> b;
            printf("%lld\n",query(a,b));
        } else if (op == 'M') {
            cin >> a >> b >> d;
            mark(a, b, d);
        } else {
            cin >> a >> b;
            del(a, b);
        }
    }
    
    
    return 0;
}