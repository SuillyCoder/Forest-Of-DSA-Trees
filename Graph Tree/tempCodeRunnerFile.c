 if (current->value == deletor && previous == NULL){
                    graphTree->adjLists[v] = current->next;
                    free(current);
                    foundIt = 1;
                }