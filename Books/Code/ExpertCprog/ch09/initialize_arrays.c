int main(){

    char *vegetables[] = { "carrot",
                       "celery",
                       "corn",
                       "cilantro",
                       "crispy fried potatoes" }; /* works
fine */
  /* will NOT compile successfully*/

/*
int *weights[] = {
                    {1,2,3,4,5},
                    {6,7},
                    {8,9,10}
                };         */

   /*
     Arrays of pointers can't be directly initialized with non-string types: */

    /* but it can be "cheated" */

    int row_1[] = {6,7,-1};
int row_2[] = {8,9,10,-1};

int *weights[] = {
                  row_1,
                  row_2
};


 

}
