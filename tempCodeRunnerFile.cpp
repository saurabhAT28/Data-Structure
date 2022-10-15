// int c,data;
//     cout<<"1 --> Insert in a tree"<<endl;
//     cout<<"2 --> Inorder Traversal"<<endl;
//     cout<<"3 --> Postorder Traversal"<<endl;
//     cout<<"4 --> Preorder Traversal"<<endl;
//     cout<<"5 --> Exit"<<endl;

//     cout<<"*********************************"<<endl;

//     do{
//         cout<<"Enter choice: ";
//         cin>>c;

//         switch(c){
//             case 1:{
//                 cout<<"Enter the data: ";
//                 cin>>data;
//                 insert(data);
//                 break;
//             }
//             case 2:{
//                 cout<<"**Inorder Traversal: ";
//                 inOrder(root);
//                 cout<<endl;
//                 break;
//             }
//             case 3:{
//                 cout<<"**Postrder Traversal: ";
//                 postOrder(root);
//                 cout<<endl;
//                 break;
//             }
//             case 4:{
//                 cout<<"**Prerder Traversal: ";
//                 preOrder(root);
//                 cout<<endl;
//                 break;
//             }
//             case 5:{
//                 cout<<"Thank you!!"<<endl;
//                 cout<<"E X I T"<<endl;
//                 break;
//             }
//             default :{
//                 cout<<"Please enter valid choice."<<endl;
//             }     
//         }
//         cout<<"*********************************"<<endl;
//     }while(c!=5);