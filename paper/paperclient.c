#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "paperserver.h"

CLIENT *cl;

void print_usage(char *name) {
    printf("Syntax:\n");
    printf("\t%s <hostname> -a \'<Author Name>\' \'<Paper title>\' <file>\n", name);
    printf("\t\tAdd an article\n\n");
    printf("\t%s <hostname> -f <document number>\n", name);
    printf("\t\tFetch an article\n\n");
    printf("\t%s <hostname> -i <document number>\n", name);
    printf("\t\tGet article information\n\n");
    printf("\t%s <hostname> -r <document number>\n", name);
    printf("\t\tRemove an article\n\n");
    printf("\t%s <hostname> -l \n", name);
    printf("\t%s [-h]\n", name);
    printf("\t\tPrint usage syntax\n\n");

    return;
}

void add_article(char *author, char *title, char *filename) {
    struct add_article_in *in;
    article_num *num;

    in = (struct add_article_in *) malloc(sizeof(struct add_article_in));

    in->author = strdup(author);
    in->title = strdup(title);
    in->file_name = strdup(filename);

    num = add_1(in, cl);
    printf("%ld\n", *num);
    free(in);

    return;
}

void fetch_article(char *article) {
    return;
}

void remove_article(char *article) {
    article_num num = atol(article);
    int *ret_val;

    ret_val = remove_1(&num, cl);

    return ;
}

void get_article_info(char *article) {
    struct article_info_out *art;
    article_num num = atol(article);

    art = (struct article_info_out *) malloc(sizeof(struct article_info_out));

    art = info_1(&num, cl);
    printf("Author: %s\tTitle: %s\n", art->author, art->title);


    return;
}

void get_article_list() {
    struct list_article_out *article;

    article = list_1(NULL, cl);

    while (article) {
        printf("%ld\t%s\t%s\n", article->num, article->author, article->title);
        article = article->next;
    }

    return;

}


int main(int argc, char **argv) {
    int c, err;
    char *farg, *iarg, *rarg;
    char *hostname;
    int hflag = 0, aflag = 0, fflag = 0, iflag = 0, rflag = 0, lflag = 0; 


    while ((c = getopt(argc, argv, "haf:i:r:l")) != -1) {
        switch (c) {
        case 'h':
            hflag = 1;
            break;
        case 'a':
            aflag = 1;
            break;
        case 'f':
            farg = optarg;
            fflag = 1;
            break;
        case 'i':
            iarg = optarg;
            iflag = 1;
            break;
        case 'r':
            rarg = optarg;
            rflag = 1;
            break;
        case 'l':
            lflag = 1;
            break;
        case '?':
            err = 1;
            break;
        }      
    }

    if (hflag == 1 || argc < 2) {
        print_usage(argv[0]);
    }

    if ((argc - optind) < 1) {
        printf("hostname missing!\n");
        print_usage(argv[0]);
        exit(1);
    }
    else {
        hostname = argv[optind];
        cl = clnt_create(hostname, PAPERSERVER_PROG, PAPERSERVER_VERS, "tcp");
        if (cl == NULL) {
            perror("Error creating RPC client!");
            return 1;
        }
        else {
            printf("RPC connection succeeded!\n");
        }
    }

    if (aflag == 1) {
        if ((argc - optind) != 4) {
            printf("Incorrect amount of arguments passed!\n");
            print_usage(argv[0]);
        }
        else {
            add_article(argv[optind+1], argv[optind+2],argv[optind+3]);
        }
    }

    if (fflag == 1) {
        // printf("farg: %s\n", farg);
        fetch_article(farg);
    }

    if (rflag == 1) {
        // printf("rarg: %s\n", rarg);
        remove_article(rarg);
    }

    if (iflag == 1) {
        // printf("iarg: %s\n", iarg);
        get_article_info(iarg);
    }

    if (lflag == 1) {
        get_article_list();
    }

    // printf("optind: %d\n", optind);
    // int i;
    // for (i = 0; i < argc; i++) {
    //     printf("%s ", argv[i]);
    // }
    // printf("\n");

    clnt_destroy(cl);


    return 0;
}