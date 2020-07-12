/*
Print Level Wise
Send Feedback
Given a generic tree, print the input tree in level wise order. ####For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
wherer, N is data of any node present in the binary tree. x1, x2, x3, ...., xn are the children of node N
There is no space in between.
You need to print all nodes in the level order form in different lines.
Input format :
Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Level wise print
Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output :
10:20,30,40
20:40,50
30:
40:
40:
50:
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
	public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data) {
		this->data = data;
	}

};


void printLevelWise(TreeNode<int>* root) {

    queue<TreeNode<int>*> q;

    q.push(root);

    while(!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        cout << front -> data << ":";

        for(int i = 0; i < front->children.size(); i++){
            // cout << front->children[i]->data << ",";
            if(i!=front->children.size()-1)
            {
                cout<<front->children[i]->data<<",";
            }
            else
            {
                cout<<front->children[i]->data;
            }
            q.push(front->children[i]);

        }
        cout << endl;
    }

}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}
