typedef struct type_of_vector {
    int *array;
    int count;
} vector;

vector *vector_created(int index, int stolb);
void vector_saved(vector *num_vec_1, vector *num_vec_2, int index, int stolb);
void vector_print(vector *num_vec_1, vector *num_vec_2, int index, int stolb);
