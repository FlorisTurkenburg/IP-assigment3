struct add_article_in {
    string author<>;  
    string title<>;
    string file_name<>;
};

struct list_article_out {
    long num;
    string author<>;
    string title<>;
    struct list_article_out *next;
};

struct article_info_out {
    string author<>;
    string title<>;
};

typedef long article_num;



program PAPERSERVER_PROG {
    version PAPERSERVER_VERS {
        article_num ADD(add_article_in) = 1;    /* Procedure nb */
        list_article_out LIST() = 2;            /* Procedure nb */
        article_info_out INFO(article_num) = 3; /* Procedure nb */
        int REMOVE(article_num) = 4;            /* Procedure nb */
    } = 1;                                      /* Version nb */
} = 0x20004321;                                 /* Program number */