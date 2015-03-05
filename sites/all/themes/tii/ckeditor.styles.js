/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet( 'drupal',
    [
            /* TII custom text classes */
        { name : 'Team Name (h3)'	, element : 'h3', attributes : { 'class' : 'team-name' } },  
        { name : 'Team Job Title (p)'	, element : 'p', attributes : { 'class' : 'team-title' } },  
        { name : 'Small Text', element : 'span', attributes : { 'class' : 'smalltext' } },
        { name : 'Quote', element : 'p', attributes : { 'class' : 'quote' } },
        { name : 'Image on Left' , element : 'img', attributes : { 'class' : 'img-left' } },    
        { name : 'Image on Right' , element : 'img', attributes : { 'class' : 'img-right' } }   
    ]);
}