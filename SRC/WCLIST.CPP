// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %     Copyright (C) 1993, by WATCOM International Inc.  All rights    %
// %     reserved.  No part of this software may be reproduced or        %
// %     used in any form or by any means - graphic, electronic or       %
// %     mechanical, including photocopying, recording, taping or        %
// %     information storage and retrieval systems - except with the     %
// %     written permission of WATCOM International Inc.                 %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include <wclist.h>
#include <wclistit.h>
#include <stdlib.h>
#include <iostream.h>




//
//  This defines the list base next operation.  If there are no elements
//  in the list, NULL is returned.  NULL is also returned if the current
//  position is at the end of the list.
//

WCSLink * WCIsvListBase::base_next( const WCIsvListBase * const list,
                                    WCSLink * curr,
                                    WCbool reset = FALSE ) const {
    if( reset ) {
        curr = list->tail;
        if( curr == 0 ) {
            return( 0 );
        }
    } else if( curr == list->tail ) {
        return( 0 );
    }
    return( curr->link );
};




//
//  This defines the single list base insert operation.
//

void WCIsvListBase::base_insert( WCIsvListBase * const slist,
                                 WCSLink * const datum ) const {
    if( slist->tail == 0 ) {
        slist->tail = datum;
    } else {
        datum->link = slist->tail->link;
        slist->tail->link = datum;
    };
    slist->entry_count++;
};




//
//  This defines the list base index check.  If exceptions have been enabled,
//  a range check is thrown.  If not enabled, a reasonable valid value is
//  is picked for the index.
//

int WCIsvListBase::base_index_check( const WCIsvListBase * const slist,
                                                           int index ) const {
    int entry_index = slist->entry_count - 1;
    if( index < 0 || index > entry_index ) {
#ifdef __SW_XS
        if( (slist->exceptions() & index_range) != 0 ) {
            failure oops( index_range );
            throw( oops );
        }
#endif
        if( index < 0 ) {
            index = 0;
        } else {
            index = entry_index;
        };
    }
    return( index );
};




//
//  This defines the list base find operation for single link lists by
//  other routines wishing to ensure they can access the previous entry.
//  This routine assumes a non-empty list.
//

WCSLink * WCIsvListBase::base_bfind( const WCIsvListBase * const slist,
                                                            int index ) const {
    index = base_index_check( slist, index );
    WCSLink * ret_val = slist->tail;
    while( index-- > 0 ) {
        ret_val = ret_val->link;
    }
    return( ret_val );
};




//
//  This defines the list base find operation for single link lists.
//  If there are no elements in the list, NULL is returned.  
//

WCSLink * WCIsvListBase::base_sfind( const WCIsvListBase * const slist,
                                                            int index ) const {
    if( slist->tail == 0 ) {
        return( 0 );
    };
    return( base_bfind( slist, index)->link );
};




//
//  This defines the list base find operation for double link lists.
//  If there are no elements in the list, NULL is returned.  
//

WCDLink * WCIsvListBase::base_dfind( const WCIsvListBase * const dlist,
                                                            int index ) const {
    int entry_index = dlist->entry_count - 1;
    WCDLink * ret_val = (WCDLink *)dlist->tail;
    if( ret_val == 0 || index == entry_index ) {
        return( ret_val );
    };
    if( index <= (entry_index / 2) + 1 ) {
        return( (WCDLink *)base_sfind( dlist, index ) );
    }
    index = base_index_check( dlist, index );
    index = entry_index - index;
    while( index-- > 0 ) {
        ret_val = (WCDLink *)ret_val->prev.link;
    }
    return( ret_val );
};




//
//  This defines the list base get operation.  If there are no elements
//  in the list, NULL is returned. 
//

WCSLink * WCIsvListBase::base_sget( WCIsvListBase * const slist, int index ) {
    if( slist->tail == 0 ) {
        return( 0 );
    };
    WCSLink * ret_prev = base_bfind( slist, index );
    WCSLink * ret_val = ret_prev->link;
    if( ret_val == ret_prev ) {
        slist->tail = 0;
    } else {
        ret_prev->link = ret_val->link;
        if( ret_val == slist->tail ) {
            slist->tail = ret_prev;
        }
    };
    slist->entry_count--;
    return( ret_val );
};




//
//  This defines the double linked list base get operation.  
//

WCDLink * WCIsvListBase::base_dget( WCIsvListBase * const dlist, int index ) {
    WCDLink * ret_val = base_dfind( dlist, index );
    WCDLink * ret_prev = (WCDLink *)ret_val->prev.link;
    if( ret_val == ret_prev ) {
        dlist->tail = 0;
    } else {
        ret_prev->link = ret_val->link;
        ((WCDLink *)ret_val->link)->prev.link = ret_prev;
        if( ret_val == dlist->tail ) {
            dlist->tail = ret_prev;
        }
    };
    dlist->entry_count--;
    return( ret_val );
};




//
//  This defines the list base contains operation.  If there are any
//  elements matching the supplied data, TRUE is returned.  An empty
//  list always returns a FALSE.
//
//  Note that this is a list item pointer comparison.  Value lists
//  must check the data stored in with the link.
//

WCbool WCIsvListBase::base_contains( const WCIsvListBase * const slist,
                                     WCSLink * const datum ) const {
    WCSLink * rover;

    rover = base_next( slist, rover, TRUE );
    while( rover != 0 ) {
        if( rover == datum ) {
            return( TRUE );
        }
        rover = base_next( slist, rover, FALSE );
    } 
    return( FALSE );
};




//
//  This defines the list base clear operation.  It disconnects the list
//  elements from the list.  The list object will still exist after
//  this routine is finished.  The list element objects are not cleared.
//

void WCIsvListBase::base_clear( WCIsvListBase * const slist ) {
    slist->tail = 0;
    slist->entry_count = 0;
};




//
//  This defines the list base destroy operation.  It clears the list
//  elements from the list.  The list object will still exist after
//  this routine is finished.  Since we are going to destroy every
//  element, do not worry about maintaining links.
//
//  Data objects pointed to within a list element are not cleared
//  unless the destruction of the element has been provided for
//  by the user.
//

void WCIsvListBase::base_destroy( WCIsvListBase * const slist ) {
    WCSLink * rover;
    WCSLink * next_link;

    rover = base_next( slist, rover, TRUE );
    while( rover != 0 ) {
        next_link = base_next( slist, rover, FALSE );
        delete rover;
        rover = next_link;
    } 
    base_clear( slist );
};




//
//  This defines the list base destructor.  If there are any problems, it
//  checks for a user supplied indication of an exception handler, and if
//  found, throws an exception.
//
//  Exceptions are cleared before throwing since it is an error to throw
//  an exception while stack unwinding from a destructor.
//
//  If the list is not empty, and no exception can be thrown, the list is
//  cleared.  
//

WCIsvListBase::~WCIsvListBase() {
    if( tail != 0 ) {
#ifdef __SW_XS
        if( (this->exceptions() & not_empty) != 0 ) {
            this->exceptions( 0 );
            failure oops( not_empty );
            throw( oops );
        }
#endif
        base_destroy( this );
    }
};




//
//  This defines the routine that advances through a list for an iterator
//  class.
//

WCSLink * WCListIterBase::base_advance( WCListIterBase * const iterb,
                                                       int adv_amount ) {
    WCSLink * list_item = iterb->curr_item;
    if( iterb->at_end ) {
        if( list_item != 0 ) {
            iterb->curr_item = 0;
            iter_undefined( iterb );
        }
        return( 0 );
    }
    if( adv_amount < 1 ) {
        range_bad( iterb );
        adv_amount = 1;
    }
    WCSLink * list_tail = iterb->curr_list->tail;
    if( list_item == 0 ) {
        list_item = list_tail;
    }
    while( adv_amount-- > 0 ) {
        list_item = list_item->link;
        if( list_item == list_tail ) {
            iterb->at_end = TRUE;
            if( adv_amount > 0 ) {
                iterb->curr_item = 0;
                iter_undefined( iterb );
                return( 0 );
            }
        }
    }
    iterb->curr_item = list_item;
    return( list_item );
}




//
//  This defines the routine that retreats through a list for an iterator
//  class.
//

WCDLink * WCListIterBase::base_retreat( WCListIterBase * const iterb,
                                                      int adv_amount ) {
    if( adv_amount < 1 ) {
        range_bad( iterb );
        adv_amount = 1;
    }
    WCSLink * list_item = iterb->curr_item;
    if( iterb->at_end || list_item == 0 ) {
        iter_undefined( iterb );
        return( 0 );
    }
    WCSLink * list_tail = iterb->curr_list->tail;
    while( adv_amount-- > 0 ) {
        list_item = ((WCDLink *)list_item)->prev.link;
        if( list_item == list_tail ) {
            iterb->at_end = TRUE;
            iterb->curr_item = 0;
            iter_undefined( iterb );
            return( 0 );
        }
    }
    iterb->curr_item = list_item;
    return( (WCDLink *)list_item );
}




//
//  This defines the routine that hits the tail pointer with a new value
//  so that inserts/appends can easily be done in the middle of a list.
//  A zero is returned if the are no items on the list, or the tail is
//  equal to the current item.
//

WCSLink * WCListIterBase::base_tail_hit( WCListIterBase * const iterb,
                                                   WCSLink * new_tail ) {
    WCSLink * list_tail = iterb->curr_list->tail;
    if( list_tail == new_tail ) {
        list_tail = 0;
    }
    iterb->curr_list->tail = new_tail;
    return( list_tail );
}




//
//  This defines the routine that hits the tail pointer with a new value
//  so that inserts/appends can easily be done in the middle of a list.
//  A zero is returned if the are no items on the list, or the tail is
//  equal to the current item.
//

void WCListIterBase::base_tail_unhit( WCListIterBase * const iterb,
                                                WCSLink * old_tail ) {
    if( old_tail != 0 ) {
        iterb->curr_list->tail = old_tail;
    }
}




//
//  This routine checks for exceptions enabled for the current iterator
//  item being undefined.  If the exception has been set, throw it.
//

#pragma off (unreferenced)
void WCListIterBase::item_undefined( WCListIterBase * const iterb ) {
#ifdef __SW_XS
    if( (iterb->exceptions() & undef_item) != 0 ) {
        failure oops( undef_item );
        throw( oops );
    }
#endif
}
#pragma on (unreferenced)




//
//  This routine checks for exceptions enabled for the iterator position
//  being undefined.  If the exception has been set, throw it.
//

#pragma off (unreferenced)
void WCListIterBase::iter_undefined( WCListIterBase * const iterb ) {
#ifdef __SW_XS
    if( (iterb->exceptions() & undef_iter) != 0 ) {
        failure oops( undef_iter );
        throw( oops );
    }
#endif
}
#pragma on (unreferenced)




//
//  This routine checks for exceptions enabled for the iterator advance
//  being a bad value.  If the exception has been set, throw it.
//

#pragma off (unreferenced)
void WCListIterBase::range_bad( WCListIterBase * const iterb ) {
#ifdef __SW_XS
    if( (iterb->exceptions() & iter_range) != 0 ) {
        failure oops( iter_range );
        throw( oops );
    }
#endif
}
#pragma on (unreferenced)
