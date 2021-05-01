typedef struct type_of_vector {
    int *array;
    int count;
} vector;

vector *vector_created(int index, int stolb);
void vector_saved(vector *num_vec_1, vector *num_vec_2, int index, int stolb);
void vector_print(vector *num_vec_1, vector *num_vec_2, int index, int stolb);
void vector_saved_file(vector *num_vec_1, vector *num_vec_2, int index, int stolb, FILE * file);
void vector_multiplex(vector *num1, vector *integer1, vector *num2, vector *integer2, vector *num3, vector *integer3, int n1, int n2, int m1, int m2);