#include "paperserver.h"

// The head of the linked list of papers.
struct list_article_out *first_paper = NULL; 


article_num *add_1_svc(add_article_in *in, struct svc_req *rqstp) {
    static article_num out;
    struct list_article_out *cur_paper;
    struct list_article_out *new_paper;
    new_paper = (struct list_article_out *) malloc(sizeof(struct list_article_out));

    if (first_paper == NULL) { // Add the very first paper to the list
        new_paper->num = 1;
        out = 1;
        new_paper->author = strdup(in->author);
        new_paper->title = strdup(in->title);
        // printf("in_author%s\tin_title%s\n", in->author, in->title);
        // printf("paper_author%s\tpaper_title%s\n", paper->author, paper->title);
        new_paper->next = NULL;
        first_paper = new_paper;
        // free(new_paper);
        // printf("firstpaper_author %s\tfirstpaper_title %s\n", first_paper->author, first_paper->title);
    }
    else {
        article_num first_free = 0;
        int look_for_free = 1;
        cur_paper = first_paper;
        while (cur_paper) {
            if (look_for_free == 1) {
                if (cur_paper->next != NULL) {
                    if ((cur_paper->next->num - cur_paper->num) > 1) {
                        first_free = cur_paper->num + 1;
                        look_for_free = 0;
                    }
                }
            }

            // printf("in_author %s\tin_title %s\n", in->author, in->title);
            // printf("curpaper_author %s\tcurpaper_title %s\n", cur_paper->author, cur_paper->title);
            if (strcmp(cur_paper->author, strdup(in->author)) == 0 && strcmp(cur_paper->title, strdup(in->title)) == 0) {
                // Paper already exists, update and return number
                out = cur_paper->num;
                // free(new_paper);
                return &out;
            }
            else { // Continue looking if paper exists
                if (cur_paper->next) {
                    cur_paper = cur_paper->next;
                }
                else { // End of the list reached
                    break;
                }
            }
        }
        if (look_for_free == 1) { 
            // No free number was found so add the paper at the end
            new_paper->num = cur_paper->num + 1;
            out = new_paper->num;
            new_paper->author = strdup(in->author);
            new_paper->title = strdup(in->title);
            new_paper->next = NULL;
            cur_paper->next = new_paper;
        }
        else { // Place the new paper at the free number
            cur_paper = first_paper;
            while (cur_paper) {
                if (cur_paper->num == (first_free - 1)) {
                    new_paper->author = strdup(in->author);
                    new_paper->title = strdup(in->title);
                    new_paper->num = first_free;
                    new_paper->next = cur_paper->next;
                    cur_paper->next = new_paper;
                    out = first_free;
                    break;
                }
            }
            
        }


    }
    

    // free(paper);
    // out = 0;
    return &out;
}


list_article_out *list_1_svc(void * not_used, struct svc_req *rqstp) {
    static list_article_out article_list;
    article_list.num = 1;
    article_list.author = "Henk";
    article_list.title = "Some Title";
    article_list.next = NULL;

    return &article_list;
        
}   


article_info_out *info_1_svc(article_num *num, struct svc_req *reqstp) {
    static article_info_out *article;
    struct list_article_out *paper;
    //paper = (struct list_article_out *) malloc(sizeof(struct list_article_out));
    article = (struct article_info_out *) malloc(sizeof(struct article_info_out));

    // printf("firstpaper_author %s\tfirstpaper_title %s\n", first_paper->author, first_paper->title);

    paper = first_paper;

    while (paper != NULL) {
        if (paper->num == *num) {
            article->author = strdup(paper->author);
            article->title = strdup(paper->title);
            break;
        }
        else {
            paper = paper->next;
        }
    }

    return article;   
}   

int *remove_1_svc(article_num *num, struct svc_req *rqstp) {
    static int ret_val;
    ret_val = 1;

    return &ret_val;

}