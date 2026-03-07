// void delNode(Node** head_ref, Node* del){
//     if((*head_ref) == NULL || del == NULL) return;
    
//     if((*head_ref) == del){
//         (*head_ref) = del->next;
//     }
    
//     if (del->perv != NULL){
//         del->next->perv = del->perv;
//     }
    
//     if (del->next != NULL){
//         del->next->next = del->next;
//     }
    
//     delete del;
// }