#define file_hanh_khach "datakhachhang"

struct khachhang {
    char cmnd[13];
    char ho[25];
    char ten[25];
    char phai[10];
};


struct Node {
    khachhang data;
    Node* left;
    Node* right;
    int height;
};


int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}


Node* newNode(khachhang kh) {
    Node* node = new Node();
    node->data = kh;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;


    x->right = y;
    y->left = T2;

 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;


    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;


    y->left = x;
    x->right = T2;


    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


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

const char* removeNullChars(char *input) {
    int length = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '\0') {
            input[length++] = input[i];
        }
    }
    input[length] = '\0'; 
}


int myStrlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
void deleteTree(Node *&root) {
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
