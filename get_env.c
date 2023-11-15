int builtin_env() {
    return(0);
        /*int i, j;
    int environ_size = 0;
    char **environ_sorted;

    while (environ[environ_size] != NULL) {
        environ_size++;
    }

    environ_sorted = malloc(sizeof(char *) * (environ_size + 1));
    if (environ_sorted == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }


    for (i = 0; i < environ_size; i++) {
        environ_sorted[i] = strdup(environ[i]);
        if (environ_sorted[i] == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
    }


    for (i = 0; i < environ_size - 1; i++) {
        for (j = 0; j < environ_size - i - 1; j++) {
            if (strcmp(environ_sorted[j], environ_sorted[j + 1]) > 0) {
                char *temp = environ_sorted[j];
                environ_sorted[j] = environ_sorted[j + 1];
                environ_sorted[j + 1] = temp;
            }
        }
    }


    for (i = 0; environ_sorted[i] != NULL; i++) {
        printf("%s\n", environ_sorted[i]);
        free(environ_sorted[i]);
    }

    free(environ_sorted);

    return 0;*/
}
