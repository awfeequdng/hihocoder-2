/*

个人感觉这样写更清晰一点。（动态分配内存）

*/
class Node {
public:
    Node* fail;
    Node* next[26];
    int cnt;
    Node() {
        CL(next, 0);
        fail = NULL;
        cnt = 0;
    }
};

//Node* q[10000000];

class AC_automaton : public Node{
public:
    Node *root;
    int head, tail;

    void init() {
        root = new Node();
        head = tail = 0;
    }

    void insert(char* st) {
        Node* p = root;
        while(*st) {
            if(p->next[*st-'a'] == NULL) {
                p->next[*st-'a'] = new Node();
            }
            p = p->next[*st-'a'];
            st++;
        }
        p->cnt++;
    }

    void build() {
        root->fail = NULL;
        deque<Node* > q;
        q.push_back(root);

        while(!q.empty()) {
            Node* tmp = q.front();
            Node* p = NULL;
            q.pop_front();
            for(int i = 0; i < 26; ++i) {
                if(tmp->next[i] != NULL) {
                    if(tmp == root) tmp->next[i]->fail = root;
                    else {
                        p = tmp->fail;
                        while(p != NULL) {
                            if(p->next[i] != NULL) {
                                tmp->next[i]->fail = p->next[i];
                                break;
                            }
                            p = p->fail;
                        }
                        if(p == NULL)   tmp->next[i]->fail = root;
                    }
                    q.push_back(tmp->next[i]);
                }
            }
        }
    }

    int search(char* st) {
        int cnt = 0, t;
        Node* p = root;
        while(*st) {
            t = *st - 'a';
            while(p->next[t] == NULL && p != root) {
                p = p->fail;
            }
            p = p->next[t];
            if(p == NULL)   p = root;

            Node* tmp = p;
            while(tmp != root && tmp->cnt != -1) {
                cnt += tmp->cnt;
                tmp->cnt = -1;
                tmp = tmp->fail;
            }
            st++;
        }
        return cnt;
    }
}AC;