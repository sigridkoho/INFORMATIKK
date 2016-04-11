#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "index.h"

/*	Staar i h-fila
struct index;
typedef struct index index_t;

typedef
struct query_result
{
	char *path;    // Document path
	double score;  // Document to query score
}query_result_t;
*/
struct index {
	map_t *words
	set_t *docs
}
int compare_res_by_path(void *a, void *b)
{
	
}


/*
 * Creates a new, empty index.
 */
index_t *index_create()
{
	
}

/*
 * Destroys the given index. Subsequently accessing the index will
 * lead to undefined behavior.
 */
void index_destroy(index_t *index)
{
	free(index);
}

/*
 * Adds the given path to the given index, and index the given
 * list of words under that path.
 * NOTE: It is the responsibility of index_addpath() to deallocate (free)
 *       'path' and the contents of the 'words' list.
 */
void index_addpath(index_t *index, char *path, list_t *words)
{
	
}

set_t *get_matching_documents(index_t *index, char *term)
{
	set_t *res = set_create(compareres);
	if(!map_haskey(index->words, term)) {
		return res;
	}
	
	set_t *paths = map_get(index->words,term);
	set_iter_t *pathiter = set_createiter(paths);
	while(set_hasnext(pathiter) {
		query_result_t *oneres = malloc(sizeof(query_result_t));
		oneres->path = set_next(pathiter);
		oneres->score = 0.0;
		set_add(res, oneres);
	}
	return res;
}

/*
 * Performs the given query on the given index.  If the query
 * succeeds, the return value will be a list of paths.  If there
 * is an error (e.g. a syntax error in the query), an error message
 * is assigned to the given errmsg pointer and the return value
 * will be NULL.
 */
list_t *index_query(index_t *index, list_t *query, char **errmsg)
{
	list_t *listres = list_create(compareres);
	set_t *emptyset = set_create(compareres);
	char *term = list_popfirst(query);			//words will not be processed more than once
	set_t *res = get_matching_documents(index, term);
	
	set_iter_t *setres = set_createiter(res);
	while(set_hasnext(res)) {
		list_addfirst(listres, set_next(setres);
	}
	return listres;
}
