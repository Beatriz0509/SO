#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "linked-list.h"

namespace base {

   Node* destroy(Node* list)
   {
      return NULL;
   }

   Node* append(Node* list, uint32_t nmec, char* name) {

        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        newNode->reg.nmec = nmec;
        newNode->reg.name = strdup(name); 

        newNode->next = NULL;

        if (list == NULL) {
            return newNode;
        }
        
        while (list->next != NULL) {
            list = list->next;
        }
        list->next = newNode;

        return list;
   }
    


    void print(Node* list) {
        while (list != NULL) {
            printf("NMEC: %u, Name: %s\n", list->reg.nmec, list->reg.name);
            list = list->next;
        }
    }

   int exists(Node* list, uint32_t nmec)
   {
      while (list != NULL) {
            if (list->reg.nmec == nmec) {
                return 1;
            }
            list = list->next;
      }
      return 0; 
   }

   Node* remove(Node* list, uint32_t nmec)
   {
      Node* prev = NULL;

        while (list != NULL) {
            if (list->reg.nmec == nmec) {
                if (prev == NULL) {
                    list = list->next; 
                } else {
                    prev->next = list->next; 
                }
                free(list->reg.name); 
                free(list); 
                return list; 
            }
            prev = list;
            list = list->next;
        }
        return list; 
   }

   const char *search(Node* list, uint32_t nmec)
   {
      while (list != NULL) {
            if (list->reg.nmec == nmec) {
                return list->reg.name; 
            }
            list = list->next;
        }
        return NULL; 
   }

   void swap(Node* a, Node* b) {
        Student temp = a->reg;
        a->reg = b->reg;
        b->reg = temp;
    }

   Node* sort_by_name(Node* list)
   {
      if (list == NULL || list->next == NULL) {
            
            return list;
        }

        int swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = 0;
            ptr1 = list;

            while (ptr1->next != lptr) {
                if (strcmp(ptr1->reg.name, ptr1->next->reg.name) > 0) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);

         return list;
   }

   Node* sort_by_number(Node* list)
   {
       if (list == NULL || list->next == NULL) {
            
            return list;
        }

        int swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = 0;
            ptr1 = list;

            while (ptr1->next != lptr) {
                if (ptr1->reg.nmec > ptr1->next->reg.nmec) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);

         return list;
   }
}
