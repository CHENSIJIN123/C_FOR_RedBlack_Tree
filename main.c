#include<stdio.h>
#include "tree.h"

extern NODE *root;
int main()
{
        init_tree(10);
                show_tree(root);
                printf("---------------min_of_tree is %d----\n",min_of_tree());
        int i = 0,choose = 0;
        while(1){
		printf("choose 0 :add ,1:delete\n");
		scanf("%d",&choose);
		if(choose == 0){
			printf("add key is :");
                	scanf("%d",&i);
                	insert_key(i);
                	show_tree(root);
                	printf("---------------min_of_tree is %d----\n",min_of_tree());
		}else if(choose == 1){
			printf("delete key is :");
                	scanf("%d",&i);
			delete_one(i);
                	show_tree(root);
                	printf("---------------min_of_tree is %d----\n",min_of_tree());
		}else{
			printf("choose is 0 or 1\n");
			exit(0);
		}

        }
        return 0;
}




