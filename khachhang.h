#define file_hanh_khach "datakhachhang"
// Ð?nh nghia c?u trúc khách hàng
struct khachhang {
    char cmnd[12];
    char ho[25];
    char ten[25];
    char phai[10];
};

// Ð?nh nghia c?u trúc Node cho cây AVL
struct Node {
    khachhang data;
    Node* left;
    Node* right;
    int height;
};

// Hàm d? tính chi?u cao c?a cây
int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Hàm d? t?o m?t nút m?i
Node* newNode(khachhang kh) {
    Node* node = new Node();
    node->data = kh;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// Hàm d? quay ph?i cây con
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

// Hàm d? quay trái cây con
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


int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Hàm d? chèn m?t nút m?i vào cây AVL
Node* insert(Node* node, khachhang kh) {

    if (node == NULL)
        return(newNode(kh));

    if (strcmp(kh.cmnd, node->data.cmnd) < 0)
        node->left = insert(node->left, kh);
    else if (strcmp(kh.cmnd, node->data.cmnd) > 0)
        node->right = insert(node->right, kh);
    else
        return node;


    node->height = 1 + max(height(node->left), height(node->right));


    int balance = getBalance(node);

    if (balance > 1 && strcmp(kh.cmnd, node->left->data.cmnd) < 0)
        return rightRotate(node);

    if (balance < -1 && strcmp(kh.cmnd, node->right->data.cmnd) > 0)
        return leftRotate(node);


    if (balance > 1 && strcmp(kh.cmnd, node->left->data.cmnd) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }


    if (balance < -1 && strcmp(kh.cmnd, node->right->data.cmnd) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}

bool timKiemCCCDTrongVe(chuyenbay &cb, const char* cccd) {
    for (int i = 0; i < cb.sove; ++i) {
        if (strcmp(cb.dsve[i].cccd, cccd) == 0) {
            return true;  
        }
    }
    return false;  
}

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
void luudatakhachhang(Node* nodetemp, FILE* f) {
    if (nodetemp != NULL) {
        luudatakhachhang(nodetemp->left, f);
        fwrite(&nodetemp->data, sizeof(khachhang), 1, f);
        luudatakhachhang(nodetemp->right, f);
    }
}

void Save_file_hanh_khach(Node* root) {
    FILE* f;
    if ((f = fopen(file_hanh_khach, "wb")) == NULL) {
        cout << "ERROR! Khong The Mo Hanh Khach" << endl;
        return;
    }
    luudatakhachhang(root, f);
    fclose(f);
}
void Openfilekhachhang(Node *&root) {
    FILE* f;
    if ((f = fopen(file_hanh_khach, "rb")) == NULL) {
        cout << "ERROR! Khong The Mo File Hanh Khach" << endl;
        return;
    }
    khachhang kh;

    while (fread(&kh, sizeof(khachhang), 1, f)) {
        root = insert(root, kh);
    }

    fclose(f);
}
