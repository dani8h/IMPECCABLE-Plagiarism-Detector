int display_files(char *folder_name)
{
    newline(2);
    tab(3);
    int number_of_files=0;
    struct dirent **name_list;
    int n;
    int i=0;
    int j=0;
    n = scandir(folder_name, &name_list,NULL,alphasort);
    printf("Current Directory:\t%s",getcwd(NULL,0));
    newline(2);
    tab(5);
    printf("Files Present in Current Directory");
    newline(3);
    int number_of_columns=4;
    int column_length=30;
    tab(1);
    while(i<n)
    {
        if(strcmp(name_list[i]->d_name,"..")==0 || strcmp(name_list[i]->d_name,".")==0)
        {
            free(name_list[i]);
            ++i;
            continue;
        }
        printf("%s", name_list[i]->d_name);
        space(column_length-(strlen(name_list[i]->d_name)));
        free(name_list[i]);
        ++i;
        ++j;
        if(j%number_of_columns==0)
        {
            newline(2);
            tab(1);
        }
    }
    free(name_list);
    newline(3);
    tab(3);
    return (n-2);
}