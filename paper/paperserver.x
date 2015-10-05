struct add_article_in {
    char *author;  
    char *title;
    char *file_name;
};

struct list_article {
    long num;
    char *author;
    char *title;
    struct list_article *next;
};

struct article_info {
    char *author;
    char *title;
};

typedef long article_num;



program PAPERSERVER_PROG {
    version PAPERSERVER_VERS {
        article_num ADD(add_article_in) = 1;    /* Procedure nb */
        list_article LIST() = 2;                /* Procedure nb */
        article_info INFO(article_num) = 3;     /* Procedure nb */
        int REMOVE(article_num) = 4;            /* Procedure nb */
    } = 1;                                      /* Version nb */
} = 0x20004321;                                 /* Program number */