struct add_article_in {
    string author<>;  
    string title<>;
    opaque content<>;
};

struct articles {
    long num;
    string author<>;
    string title<>;
    opaque content<>;
    struct articles *next;
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

struct fetch_article_out {
    opaque content<>;
};

typedef long article_num;



program PAPERSERVER_PROG {
    version PAPERSERVER_VERS {
        article_num ADD(add_article_in) = 1;        /* Procedure nb */
        list_article_out LIST() = 2;                /* Procedure nb */
        article_info_out INFO(article_num) = 3;     /* Procedure nb */
        int REMOVE(article_num) = 4;                /* Procedure nb */
        fetch_article_out FETCH(article_num) = 5;   /* Procedure nb */
    } = 1;                                          /* Version nb */
} = 0x20004321;                                     /* Program number */