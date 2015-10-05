#include "paperserver.h"

article_num *add_1_svc(add_article_in *in, struct svc_req *rqstp) {
    static article_num out;
    out = 0;
    return &out;
}


list_article *list_1_svc(void * not_used, struct svc_req *rqstp) {
    static list_article article_list;
    article_list.num = 1;
    article_list.author = "Henk";
    article_list.title = "Some Title";
    article_list.next = NULL;

    return &article_list;
        
}   


article_info *info_1_svc(article_num *num, struct svc_req *reqstp) {
    static article_info article;
    article.author = "Henk";
    article.title = "Some Title";

    return &article;   
}   

int *remove_1_svc(article_num *num, struct svc_req *rqstp) {
    int ret_val;
    ret_val = 1;

    return &ret_val;

}