! =====================================================================
! Infit (Italian Inform Library)
! =====================================================================
!        Author: Giovanni Riccardi (giovanni@composizioni.net)
!       Version: 2.5
!      Released: 14 October 2004
! Serial Number: 041014
!   Description: "An Inform library to write Interactive Fiction in
!                Italian."
!          Note: For use with Inform 6. (Tested with Inform compiler
!                version 6.30 and Inform library 6/11).
! =====================================================================
!
! FILES IN THE INFIT DISTRIBUTION:
!
!     Italian.h - The Inform Language Definition File for Italian.
!    ItalianG.h - The Italian Grammar File.
!     Replace.h - Some functions in the standard library are replaced
!                 here.
!   leggimi.txt - Informations in Italian.
! copyright.txt - Copyright informations (also in Italian).
!     infit.log - Changes and bug corrections made in the library
!                 (in Italian)
!    guida.html - An INFIT guide in Italian
!
! =====================================================================
!
! COPYRIGHT INFORMATIONS:
!
! Infit copyright (c) 1997 - 2004 by Giovanni Riccardi.
! Some part of the code in these files are copyright 
! (c) 1996 - 1999 by Graham Nelson
!
! Infit is free software. You can freely distribute it with these
! restrictions:
! (a) distributed copies are not substantially different from the
!     original copy archived in the Infit Web Site (see below).
! (b) distributed copies contain this copyright message.
! (c) no profit is involved in the distribution.
!
! Infit is distributed WITHOUT ANY WARRANTY.
!
! =====================================================================
!
! MORE INFO:
!
!   Inform Web Site: http://www.inform-fiction.org
!    Infit Web Site: http://www.inform-italia.org
!       Infit Email: infit@inform-italia.org
! My personal Email: giovanni@composizioni.net
!
! ===========================================================================

! LANGUAGE NOTE:
! Since Infit is intended for use of Italian IF Designers, code
! comments are written in Italian.


! Replace.h
! Numero di Serie: 041014
! -----------------------
! Il file Replace.h contiene le versioni "tradotte e adattate" di
! alcune funzioni della libreria inglese. Per utilizzarlo (necessario
! al funzionamento della Infit) si deve aggiungere un 
!       Include "Replace";
! subito dopo l'inclusione di "verblib".  


! ---------------------------------------------------------------------
! Routine della libreria standard che sono state sostituite
! ---------------------------------------------------------------------

[ Banner i;
   if (Story ~= 0) {
        #Ifdef TARGET_ZCODE;
        #IfV5; style bold; #Endif;
        print (string) Story;
        #IfV5; style roman; #Endif;
        #Ifnot; ! TARGET_GLULX;
        glk($0086, 3); ! set header style
        print (string) Story;
        glk($0086, 0); ! set normal style
        #Endif; ! TARGET_
    }
    if (Headline ~= 0) print (string) Headline;
    #Ifdef TARGET_ZCODE;
    print "Versione ", (HDR_GAMERELEASE-->0) & $03ff, " -- Numero di serie ";
    for (i=0 : i<6 : i++) print (char) HDR_GAMESERIAL->i;
    #Ifnot; ! TARGET_GLULX;
    print "Versione ";
    @aloads ROM_GAMERELEASE 0 i;
    print i;
    print " -- Numero di serie ";
    for (i=0 : i<6 : i++) print (char) ROM_GAMESERIAL->i;
    #Endif; ! TARGET_
    print "^Inform v"; inversion;
    print " -- Libreria ", (string) LibRelease, " ";
    #Ifdef LanguageVersion;
    print " --  ", (string) LanguageVersion, "    ";
    #Endif;
    #Ifdef STRICT_MODE;
    print "S";
    #Endif; ! STRICT_MODE
    #Ifdef INFIX;
    print "X";
    #Ifnot;
    #Ifdef DEBUG;
    print "D";
    #Endif; ! DEBUG
    #Endif; ! INFIX
    new_line;
];



[ VersionSub ix;
    Banner();
    #Ifdef TARGET_ZCODE;
    ix = 0; ! shut up compiler warning
    if (standard_interpreter > 0) {
        print "Interprete standard ", standard_interpreter/256,
	  ".", standard_interpreter%256, " (", HDR_TERPNUMBER->0;
        #iftrue (#version_number == 6);
        print (char) '.', HDR_TERPVERSION->0;
        #ifnot;
        print (char) HDR_TERPVERSION->0;
        #endif;
        print ") -- ";
        }
    else {
        print "Interprete ", HDR_TERPNUMBER->0, " Versione ";
        #iftrue (#version_number == 6);
        print HDR_TERPVERSION->0;
        #ifnot;
        print (char) HDR_TERPVERSION->0;
        #endif;
        print " -- ";
    }
               
    #Ifnot; ! TARGET_GLULX;
    @gestalt 1 0 ix;
    print "Interprete versione ", ix / $10000, ".", (ix & $FF00) / $100,
    ".", ix & $FF, " / ";
    @gestalt 0 0 ix;
    print "VM ", ix / $10000, ".", (ix & $FF00) / $100, ".", ix & $FF, " / ";
    #Endif; ! TARGET_;
    print "Libreria: #", (string) LibSerial, "^";
    #Ifdef LanguageSerial;
    print "Infit: #", (string) LanguageSerial;
    #Endif;
    #Ifdef LanguageCopyright;
    print " -- Infit ", (string) LanguageCopyright, "^";
    #Endif;

];


[ Objects1Sub i j f;
    L__M(##Objects, 1);
    objectloop (i has moved) {
       f = 1; print (the) i; j = parent(i);
        if (j) {
           if (j == player) {
               if (i has worn) L__M(##Objects, 3, i);
               else L__M(##Objects, 4);
                jump Obj__Ptd;
           }

            if (j has animate)   { L__M(##Objects, 5, i); jump Obj__Ptd; }
            if (j has visited)   { L__M(##Objects, 6, j); jump Obj__Ptd; }
            if (j has container) { L__M(##Objects, 8, j); jump Obj__Ptd; }
            if (j has supporter) { L__M(##Objects, 9, j); jump Obj__Ptd; }
            if (j has enterable) { L__M(##Objects, 7, j); jump Obj__Ptd; }
        }
        L__M(##Objects, 10, i);

      .Obj__Ptd;

        new_line;
    }
    if (f == 0) L__M(##Objects, 2);
];






[ PrintCommand from i k spacing_flag p pr;

    ! Parte sperimentale: è la base da cui trarrò la PrintCommand()
    ! che riunirà le funzioni di PrintPrep() e PrintInfinitive() in
    ! INFIT 3.
    !
    ! NOTA: Mi devo ricordare di usare la funzione LanguageVerb e di
    ! definire la PrintVerb (vedere anche il DM4, capitolo V).

    
!      if (from==-1)
!      {
!  	 for (k=1:k<pcount:k++)
!  	 {
!  	     i=pattern-->k;
!        	     if (i>=REPARSE_CODE)
!  	     {
! 		 pre-->0 = 99;
! 		 @output_stream 3 pre;		
!  	    	 print (address) No__Dword(i - REPARSE_CODE);	
!  	    	 @output_stream -3;	
! 		 !print (address) No__Dword(i-REPARSE_CODE);
! 		 spacing_flag = true;
! 		 jump prepOK;
! 	     }
!        	 }

! 	 .prepOK;
! 	 if (spacing_flag == true) print " c";
! 	 else print "C";
!  	 return;
	 
!     }

     if (from==0)
     {   
	i=verb_word;
       	if (LanguageVerb(i) == 0)
             if (PrintVerb(i) == 0)
               	print (address) i;
       	from++; spacing_flag = true;
     }
    
     
     for (k=from: k<pcount: k++)
     {
	i = pattern-->k;
       	if (i == PATTERN_NULL) continue;
       	if (spacing_flag) print (char) ' ';
       	if (i == 0) { print (string) THOSET__TX; jump TokenPrinted; }
       	if (i == 1) { print (string) THAT__TX; jump TokenPrinted; }
       	if (i >= REPARSE_CODE) 
       	{			
	    
	    #Ifdef TARGET_ZCODE;
	    StorageForShortName-->0 = 160;
	    @output_stream 3 StorageForShortName;
	    print (address) No__Dword(i - REPARSE_CODE);
	    @output_stream -3;
	    #Ifnot; ! TARGET_GLULX
	    PrintToBuffer(StorageForShortName, 160, No__Dword(i - REPARSE_CODE));
	    #Endif; ! TARGET_
	    
	    p = StorageForShortName->WORDSIZE;
 	    
	    switch(p)
	    {
 		'a': pr = 1; 
 		's': pr = 2; 
 		'd': if (StorageForShortName->(WORDSIZE+1) == 'e') pr = 4; else pr = 3;
 		'i': pr = 4; 
 		default: print (address) No__Dword(i - REPARSE_CODE);
 	    }
	}
      	
       	else 
       	{
	    if (i in compass && LanguageVerbLikesAdverb(verb_word))
                LanguageDirection (i.door_dir);
	    else 
	        switch (pr)
		{
 			1: print (arta) i;
			2: print (artsu) i;
 			3: print (artda) i;
 			4: print (artin) i; 
 			default: print (the) i;
       		}	
       	}
     	 
       	 .TokenPrinted;
       	 spacing_flag = true;
     }
        
 ];


! GenericVerb serve per gestire il verbo "fai"

[ GenericVerbSub; L__M(##GenericVerb,1); ];
