#include <string.h>
#include <tb2sac.h>


/*
*
*/
int compare_SCNL( const void *a, const void *b )
{
	int ret;
	TRACE_NODE *trace_a = (TRACE_NODE *)a;
	TRACE_NODE *trace_b = (TRACE_NODE *)b;

	ret = strcmp(trace_a->sta, trace_b->sta);
	if ( ret ) return ret;
	ret = strcmp(trace_a->chan, trace_b->chan);
	if ( ret ) return ret;
	ret = strcmp(trace_a->net, trace_b->net);
	if ( ret ) return ret;
	ret = strcmp(trace_a->loc, trace_b->loc);
	return ret;
}

/*
*
*/
int compare_time( const void *a, const void *b )
{
	TBUF *ta = (TBUF *)a;
	TBUF *tb = (TBUF *)b;

	if ( ta->time > tb->time )
		return 1;
	else if ( ta->time < tb->time )
		return -1;
	else
		return 0;
}
