
// �?nh nghia c?u tr�c kh�ch h�ng
struct khachhang {
    char cmnd[12];
    char ho[25];
    char ten[25];
    char phai[10];
};

// �?nh nghia c?u tr�c Node cho c�y AVL
struct Node {
    khachhang data;
    Node* left;
    Node* right;
    int height;
};

// H�m d? t�nh chi?u cao c?a c�y
int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// H�m d? t?o m?t n�t m?i
Node* newNode(khachhang kh) {
    Node* node = new Node();
    node->data = kh;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// H�m d? quay ph?i c�y con
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Th?c hi?n quay
    x->right = y;
    y->left = T2;

    // C?p nh?t chi?u cao
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Tr? v? g?c m?i
    return x;
}

// H�m d? quay tr�i c�y con
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Th?c hi?n quay
    y->left = x;
    x->right = T2;

    // C?p nh?t chi?u cao
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Tr? v? g?c m?i
    return y;
}

// H�m d? l?y h? s? c�n b?ng c?a m?t n�t
int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// H�m d? ch�n m?t n�t m?i v�o c�y AVL
Node* insert(Node* node, khachhang kh) {
    // 1. Th?c hi?n ch�n b�nh thu?ng c?a c�y BST
    if (node == NULL)
        return(newNode(kh));

    if (strcmp(kh.cmnd, node->data.cmnd) < 0)
        node->left = insert(node->left, kh);
    else if (strcmp(kh.cmnd, node->data.cmnd) > 0)
        node->right = insert(node->right, kh);
    else // C�c kh�a b?ng nhau kh�ng du?c ph�p trong BST
        return node;

    // 2. C?p nh?t chi?u cao c?a n�t t? ti�n n�y
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. L?y h? s? c�n b?ng c?a n�t t? ti�n n�y d? ki?m tra xem
    // n�t n�y c� b? m?t c�n b?ng hay kh�ng
    int balance = getBalance(node);

    // N?u n�t n�y tr? n�n m?t c�n b?ng, th� c� 4 tru?ng h?p

    // Tru?ng h?p Left Left
    if (balance > 1 && strcmp(kh.cmnd, node->left->data.cmnd) < 0)
        return rightRotate(node);

    // Tru?ng h?p Right Right
    if (balance < -1 && strcmp(kh.cmnd, node->right->data.cmnd) > 0)
        return leftRotate(node);

    // Tru?ng h?p Left Right
    if (balance > 1 && strcmp(kh.cmnd, node->left->data.cmnd) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Tru?ng h?p Right Left
    if (balance < -1 && strcmp(kh.cmnd, node->right->data.cmnd) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Tr? v? con tr? n�t (kh�ng thay d?i)
    return node;
}

// H�m d? t�m ki?m kh�ch h�ng trong c�y AVL
Node* search(Node* root, const char* cmnd) {
    if (root == NULL || strcmp(root->data.cmnd, cmnd) == 0)
        return root;

    if (strcmp(root->data.cmnd, cmnd) < 0)
        return search(root->right, cmnd);

    return search(root->left, cmnd);
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    
    delete root;
}


