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
! =====================================================================

! LANGUAGE NOTE:
! Since Infit is intended for use of Italian IF Designers, code
! comments are written in Italian.


! Italian.h (Italian Language Definition File).
! Numero di Serie: 041014

System_file;
Replace PrintCommand;
Replace Banner;
Replace VersionSub;
Replace Objects1Sub;


! La seguente dichiarazione di costante serve per il test della
! libreria. Se sospettate che qualche bug nel vostro gioco possa
! dipendere da INFIT, togliete il commento (o ridefinite la costante
! nel vostro gioco) e inviatemi lo script con l'errore.

! Constant INFIT_TEST; 

! =====================================================================
!   Parte I.   Preliminari
! =====================================================================

Constant LanguageVersion = "Infit v2.5";
Constant LanguageSerial = "041014";
Constant LanguageCopyright = "(c) 2004 by Giovanni Riccardi";

message "Using Infit v2.5 / Serial: 041014 / (c) 2004 by Giovanni
    Riccardi^"; 


! ---------------------------------------------------------------------
! Lettere accentate 
! ---------------------------------------------------------------------

! Solo per ZCODE


#Ifdef TARGET_ZCODE;
Zcharacter '@`a';
Zcharacter '@`e';		
Zcharacter '@`i';		
Zcharacter '@`o';		
Zcharacter '@`u';		
Zcharacter '@`E';
#Endif; ! TARGET_

! ---------------------------------------------------------------------
! La Bussola
! ---------------------------------------------------------------------

! Modificata la classe CompassDirection rispetto a INFIT 2.2 per 
! compatibilità con le librerie 6/11. Modificati anche gli oggetti 
! "direzione"

Class	CompassDirection
 with	article "il", number 0,
	description [;
		if (location provides compass_look && location.compass_look(self)) rtrue;
		if (self.compass_look()) rtrue;
		L__M(##Look, 7, self);
	],
	compass_look false,
  has	scenery;

Object Compass "bussola" 
has concealed female;

#IFNDEF WITHOUT_DIRECTIONS;

CompassDirection -> n_obj "nord"
with name 'n//' 'nord' 'north', 
	 door_dir n_to;

CompassDirection -> s_obj "sud"
with name 's//' 'sud' 'south', 
 	 door_dir s_to;

CompassDirection -> e_obj "est"
with name 'e//' 'est' 'east', 
	 article "l^", 
	 door_dir e_to;
	 
CompassDirection -> w_obj "ovest"
with name 'o//' 'ovest' 'west' 'w//',
	 article "l^",
	 door_dir w_to;
	 
CompassDirection -> ne_obj "nordest"
with name 'ne' 'nordest' 'northeast',
	 door_dir ne_to;

CompassDirection -> nw_obj "nordovest"
with name 'no//' 'nov' 'nordovest' 'northwest' 'nw',
	 door_dir nw_to;

CompassDirection -> se_obj "sudest"
with name 'se' 'sudest' 'southeast',
	 door_dir se_to;

CompassDirection -> sw_obj "sudovest"
with name 'so' 'sudovest' 'southwest' 'sw',
	 door_dir sw_to;

CompassDirection -> u_obj "sopra"
with name 'su' 'sopra' 'soffitto' 'alto' 'a//' 'up' 'u//',
	 door_dir u_to;

CompassDirection -> d_obj "sotto"
with name 'gi@`u' 'giu' 'giu^' 'sotto' 'pavimento' 'basso' 'b//' 'down' 'd//',
	 door_dir d_to;

#ENDIF;

CompassDirection -> out_obj "fuori"
with name 'fuori' 'out' 'esterno' 'esternamente',
	 door_dir out_to;

CompassDirection -> in_obj "dentro"
with name 'dentro' 'in' 'interno' 'internamente',
	 door_dir in_to;


! =====================================================================
!   Parte II.   Vocabolario
! =====================================================================

! ---------------------------------------------------------------------
! Miscellanea
! ---------------------------------------------------------------------
Constant AGAIN1__WD		= 'ancora';
Constant AGAIN2__WD		= 'ancora';
Constant AGAIN3__WD		= 'rifai';
Constant OOPS1__WD		= 'oops';
Constant OOPS2__WD		= 'oops';
Constant OOPS3__WD		= 'oops';
Constant UNDO1__WD		= 'annulla';
Constant UNDO2__WD		= 'a';
Constant UNDO3__WD		= 'undo';

Constant ALL1__WD		= 'tutto';
Constant ALL2__WD		= 'ogni';
Constant ALL3__WD		= 'tutti';
Constant ALL4__WD		= 'ognuno';
Constant ALL5__WD		= 'entrambi';
Constant AND1__WD		= 'e//';
Constant AND2__WD		= 'e//';
Constant AND3__WD		= 'e//';
Constant BUT1__WD		= 'ma';
Constant BUT2__WD		= 'eccetto';
Constant BUT3__WD		= 'per@`o';
Constant ME1__WD		= 'me';
Constant ME2__WD		= 'stesso';
Constant ME3__WD		= 'stesso';
Constant OF1__WD		= 'di';
Constant OF2__WD		= 'dello';
Constant OF3__WD		= 'della';
Constant OF4__WD		= 'degli';
Constant OTHER1__WD		= 'altra';
Constant OTHER2__WD		= 'un^altra';
Constant OTHER3__WD		= 'altro';
Constant THEN1__WD		= 'allora';
Constant THEN2__WD		= 'poi';
Constant THEN3__WD		= 'quindi';

Constant NO1__WD		= 'n//';
Constant NO2__WD		= 'no//';
Constant NO3__WD		= 'no';
Constant YES1__WD		= 's//';
Constant YES2__WD		= 'si';
Constant YES3__WD		= 's@`i';

Constant AMUSING__WD		= 'divertenti';
Constant FULLSCORE1__WD		= 'completo';
Constant FULLSCORE2__WD		= 'fullscore';
Constant QUIT1__WD		= 'quit';
Constant QUIT2__WD		= 'uscire';
Constant RESTART__WD		= 'ricominciare';
Constant RESTORE__WD		= 'caricare';


! ---------------------------------------------------------------------
! Pronomi
! ---------------------------------------------------------------------
Array LanguagePronouns table

   ! word     possible GNAs	connected
   !          to follow:	to:
   !          a     i
   !          s  p  s  p
   !          mfnmfnmfnmfn               

     'lui'  $$100000000000       NULL  
     'lei'  $$010000000000       NULL
     'esso' $$100000100000       NULL      
     'essa' $$010000010000       NULL      
     'gli'  $$100000000000       NULL 
     'essi' $$000110000110       NULL
     'esse' $$000010000010       NULL
     'loro' $$000110000110       NULL; 
  

! ---------------------------------------------------------------------
! Descrittori (articoli, pronomi possessivi, ecc.)
! ---------------------------------------------------------------------

Array LanguageDescriptors table

   !  word	 possible GNAs		descriptor	connected
   !             to follow:		type:           to:
   !             a     i
   !             s  p  s  p
   !             mfnmfnmfnmfn               

      'mio'    $$100000100000		POSSESS_PK      0
      'mia'    $$010000010000		POSSESS_PK      0
      'miei'   $$000100000100		POSSESS_PK      0
      'mie'    $$000010000010		POSSESS_PK      0
    
      'questo' $$100000100000		POSSESS_PK      0
      'questa' $$010000010000		POSSESS_PK      0
      'questi' $$000100000100		POSSESS_PK      0
      'queste' $$000010000010		POSSESS_PK      0	
    
      'quello' $$100000100000		POSSESS_PK      1
      'quella' $$010000010000		POSSESS_PK      1
      'quell^' $$110000110000		POSSESS_PK      1
      'quelli' $$000100000100		POSSESS_PK      1
      'quegli' $$000100000100		POSSESS_PK      1
      'quelle' $$000010000010		POSSESS_PK      1

      'suo'    $$100000100000		POSSESS_PK      'lui'
      'suoi'   $$000100000100		POSSESS_PK      'lui'
      'sua'    $$010000010000		POSSESS_PK      'lei'
      'sue'    $$000010000010		POSSESS_PK      'lei'
      'loro'   $$000110000110		POSSESS_PK      'loro'
    
      'il'     $$100000100000		DEFART_PK       NULL
      'lo'     $$100000100000		DEFART_PK       NULL
      'la'     $$010000010000		DEFART_PK       NULL
      'l^'     $$110000110000		DEFART_PK       NULL
      'i//'    $$000100000100		DEFART_PK       NULL
      'gli'    $$000100000100		DEFART_PK       NULL
      'le'     $$000010000010		DEFART_PK       NULL
    
      'un'     $$100000100000		INDEFART_PK     NULL
      'uno'    $$100000100000		INDEFART_PK     NULL
      'una'    $$010000010000		INDEFART_PK     NULL
      'un^'    $$010000010000		INDEFART_PK     NULL
      'dei'    $$000100000100		INDEFART_PK     NULL
      'degli'  $$000100000100		INDEFART_PK     NULL
      'delle'  $$000010000010		INDEFART_PK     NULL
      'alcuni' $$000100000100		INDEFART_PK     NULL
      'alcune' $$000010000010		INDEFART_PK     NULL
    
    
      'illuminato' $$100000100000	light		NULL
      'illuminata' $$010000010000	light		NULL
      'illuminati' $$000100000100	light		NULL
      'illuminate' $$000010000010	light		NULL
      'buio'       $$100000100000	(-light)	NULL
      'buia'       $$010000010000	(-light)	NULL
      'bui'        $$000100000100	(-light)	NULL
      'buie'       $$000010000010	(-light)	NULL
    
    
      'acceso' $$100000100000		light		NULL
      'accesa' $$010000010000		light		NULL
      'accesi' $$000100000100		light		NULL
      'accese' $$000010000010		light		NULL
      'spento' $$100000100000		(-light)	NULL
      'spenta' $$010000010000		(-light)	NULL
      'spenti' $$000100000100		(-light)	NULL
      'spente' $$000010000010		(-light)	NULL;
          
    
    
! ---------------------------------------------------------------------
! Numeri
! ---------------------------------------------------------------------
Array LanguageNumbers table
    'uno' 1 'due' 2 'tre' 3 'quattro' 4 'cinque' 5
    'sei' 6 'sette' 7 'otto' 8 'nove' 9 'dieci' 10
    'undici' 11 'dodici' 12 'tredici' 13 'quattordici' 14
    'quindici' 15 'sedici' 16 'diciassette' 17 'diciotto' 18
    'diciannove' 19 'venti' 20;

! =====================================================================
!   Parte III.   Traduzione
! =====================================================================

! Distinguo la versione ZCODE da quella GLULX dell'array parse utilizzando 
! la tecnica suggerita da Roger Firth nell'articolo "How is the parse 
! array structured?" nell'Inform FAQ 
! (http://www.firthworks.com/roger/informfaq/ii.html#14). 

[ tokenCount;
	#Ifdef TARGET_ZCODE;
	return parse->1;
	#Ifnot; ! TARGET_GLULX
	return parse-->0;
	#Endif; ! TARGET_
];

[ tokenDict w;  
	#Ifdef TARGET_ZCODE;
	return parse-->(2*w - 1);
	#Ifnot; ! TARGET_GLULX
	return parse-->(3*w - 2);
	#Endif; ! TARGET_
];

[ tokenLen w;   
	#Ifdef TARGET_ZCODE;
	return parse->(4*w);
	#Ifnot; ! TARGET_GLULX
	return parse-->(3*w - 1);
	#Endif; ! TARGET_
];

[ tokenPos w;
      #Ifdef TARGET_ZCODE;
      return parse->(4*w + 1);
      #Ifnot; ! TARGET_GLULX
      return parse-->(3*w);
      #Endif; ! TARGET_
];




[LanguageToInformese x word at word1 len;

    
    ! Aggiunge uno spazio dopo ogni apostrofo.
    !
    ! MODIFICATA: sostituito 2 con WORDSIZE perchè
    ! in Glulx la frase è memorizzata in buffer a partire
    ! dalla posizione 4 anziché dalla 2. Inoltre, il numero
    ! di caratteri della frase è memorizzato in 3 e non in 1
    ! Ricapitolando
    !
    !     Inizio frase: buffer->WORDSIZE
    ! Numero caratteri: buffer->(WORDSIZE-1)
    
    for (x=WORDSIZE:x<(WORDSIZE+buffer->(WORDSIZE-1)):x++)
    {
	if (buffer->x == ''') 
	{
	    LTI_Insert(x+1, ' ');
	    Tokenise__(buffer,parse);
	    continue;
	}
    }

    ! Inizio del ciclo sull'array "parse" per la sostituzione di
    ! alcune parole non riconosciute dal parser o riconosciute con
    ! difficoltà.
    ! Modificato per richiamare le routine token... Comincio a contare
    ! da 0 anziché da 1 e naturalmente dopo Tokenise__ imposto x=0 e non
    ! più x=-1
	
    for (x=1:x<=tokenCount():x++)
    {
	
	word = tokenDict(x);
	word1 = tokenDict(x+1);
	at = tokenPos(x);
	len = tokenLen(x);

	
	! La seguente routine traduce le parole "tutta, tutte,
     	! ognuna, entrambe", che non ho potuto dichiarare come
	! ALL*_WD, in altre parole conosciute dal parser (ci
	! sono solo 5 costanti di questo tipo disponibili).

	if (word == 'tutta' or 'tutte')     
      	{
	    buffer->(at+4) = 'o';                                        
            Tokenise__(buffer,parse);                                       
            x=0; continue;                                                
      	}

	if (word == 'ognuna')                    
        {	
	    buffer->(at+5) = 'o';                 
            Tokenise__(buffer,parse);           
            x=0; continue;                    
     	}

	if (word == 'entrambe')                                           
      	{
	    buffer->(at+7) = 'i';                                          
            Tokenise__(buffer,parse);                                        
            x=0; continue;                                                 
	}

	! Lo stesso di sopra ma per OF*_WD (le parole "del, dell',
	! delle").
	
	if (word == 'del')                  
     	{
     	    buffer->(at+1) = 'i';           
            buffer->(at+2) = ' ';
            Tokenise__(buffer,parse);          
            x=0; continue;
	}
	
        if (word == 'dell^' or 'delle')     
        {
	    buffer->(at+4) = 'o';           
            Tokenise__(buffer,parse);         
            x=0; continue;                  
     	}
     	
     	if (word == 'd^')
     	{
	    buffer->(at+1) = 'i';           
            Tokenise__(buffer,parse);         
            x=0; continue;                  
     	}
     	
	
	! Poichè non ho potuto dichiarare "me stesso" come ME*_WD (le
	! costanti sono fatte di una sola parola), allora questa
	! routine elimina semplicemente la parola "me": Infatti
	! "stesso" è conosciuta dal parser.
	!
	! 10 ottobre 2004: sostituito parse->1 con tokenCount()
  
	if (word == 'me' && word1 == 'stesso' && tokenCount()>=3)
      	{	    
	    buffer->at = ' ';            
            buffer->(at+1) = ' ';
	    Tokenise__(buffer,parse);
            x=0; continue;                     
	}

	
	! La stessa cosa di sopra ma per "punteggio completo" in cui
	! la parola "punteggio" viene semplicemente eliminata. In
	! questo modo si risolve un bug con la routine AfterGameOver
	! di parserm.h che richiama le parole FULLSCORE1_WD e
	! FULLSCORE2_WD

	if (word == 'punteggio' && word1 == 'completo')
      	{
	    buffer->at = ' ';            
            buffer->(at+1) = ' ';
	    buffer->(at+2) = ' ';
	    buffer->(at+3) = ' ';
	    buffer->(at+4) = ' ';
	    buffer->(at+5) = ' ';
	    buffer->(at+6) = ' ';
	    buffer->(at+7) = ' ';
	    buffer->(at+8) = ' ';
            Tokenise__(buffer,parse);         
            x=0; continue;                     
	}

	

	! Il comando ANNULLARE, una delle opzioni alla fine di un gioco
	! non viene riconoscita dal parser perché non è inserita tra le
	! UNDO*__WD. La parola ANNULLARE viene allora semplicemnte 
	! trasformata in ANNULLA che è riconosciuta dal parser.

	if (word == 'annullare')
	{
	    buffer->(at+len-2) = ' ';
      	    buffer->(at+len-1) = ' ';
            Tokenise__(buffer,parse);         
            x=0; continue;                     
	}



	! Gestisce il problema con la direzione NordOvest (abbreviata
 	! con 'no') che veniva confusa dal parser con la risposta
	! negativa. Notare che nelle domande la risposta negativa è
	! gestita correttamente grazie alla chiamata alla routine
	! YesOrNo. 

	if (word == 'no')
	{
	    LTI_Insert(at+2, 'v');
	    Tokenise__(buffer,parse);
	    x=0; continue;
	}


	! Gestisce alcuni comandi non troppo belli da vedersi ma a
	! quanto pare molto utilizzati tipo 'xlo' per 'esaminalo' e
	! 'llo' per 'guardalo'
         
        if (word == 0 &&		! "llo", "lla", ecc. 
	    buffer->at == 'l' && 
	    buffer->(at+1) == 'l' && 
	    (buffer->(at+2) == 'o' or 'a' or 'i' or 'e'))                    
        {
	    buffer->at = 'g';
            LTI_Insert(at+1, 'u');
            LTI_Insert(at+2, 'a');
            LTI_Insert(at+3, 'r');
            LTI_Insert(at+4, 'd');
            LTI_Insert(at+5, 'a');
            Tokenise__(buffer,parse);
            x=0; continue;
        }

        if (word == 0 &&		! "xlo", "xla", ecc. 
	    buffer->at == 'x' && 
	    buffer->(at+1) == 'l' && 
	    (buffer->(at+2) == 'o' or 'a' or 'i' or 'e'))
        {
	    buffer->at = 'e';
            LTI_Insert(at+1, 's');
            LTI_Insert(at+2, 'a');
            LTI_Insert(at+3, 'm');
            LTI_Insert(at+4, 'i');
            LTI_Insert(at+5, 'n');
            LTI_Insert(at+6, 'a');
            Tokenise__(buffer,parse);
            x=0; continue;
        }                     


! 20 Ottobre 2002
! Ho dovuto inserire il codice seguente per gestire
! il verbo 'dai' con attaccato il pronome. Queste parole non sono
! riconosciute dalla routine generica perché "dallo", ecc. sono
! parole del dizionario (preposizioni nella grammatica dei verbi).
! Ora però c'è il seguente problema: ogni preposizione è riconosciuta
! come verbo e trasformata conseguentemente. Ad esempio: "Togli il
! libro dalla scrivania" diventa "Togli il libro dai essa
! scrivania". Allo stato corrente la libreria non riconosce i verbi
! "dallo", "dalla", "dalli" e "dalle". Corregere!!!!

!    if (word == 'dallo' or 'dalla' or 'dalli' or 'dalle')
!	{	
!	 buffer->(at+2) = 'i';
!        Tokenise__(buffer,parse);
!        x=0; continue;
!       }
! TOLTA (da ricontollare bene!!!!!!!!)



	! Questa routine per prima cosa riconosce se un pronome è
	! attaccato ad un verbo quindi separa le due parole.
	! Riconosce anche alcune forme irregolari (per esempio
	! "daglielo" --> "da esso a lui).

        if (word == 0 && buffer->(at+len-3) == 'm' &&
	    buffer->(at+len-2) == 'm' && buffer->(at+len-1) == 'i')
	{
	    LTI_Insert(at+len-3, ' ');
	    buffer->(at+len-2) = 'a';
 	    LTI_Insert(at+len-1, ' ');
	    buffer->(at+len) = 'm';
	    buffer->(at+len+1) = 'e';
	    Tokenise__(buffer,parse);
            x=0; continue;	    
	}
	
	
	if (word == 0 && buffer->(at+len-3) == 'g' &&
	    buffer->(at+len-2) == 'l' && buffer->(at+len-1) == 'i')
	{
	    LTI_Insert(at+len-3, ' ');
            buffer->(at+len-2) = 'l';
            buffer->(at+len-1) = 'u';
            !buffer->(at+len) = 'i';
            Tokenise__(buffer,parse);
            x=0; continue;
	}

	
	if (word == 0 && buffer->(at+len-2) == 'l' &&
	    (buffer->(at+len-1) == 'a' or 'o' or 'i' or 'e'))
	{
	    buffer->(at+len-2) = ' ';
            LTI_Insert(at+len-1, 's');
            LTI_Insert(at+len-1, 's');
            LTI_Insert(at+len-1, 'e');
      	    if (word == 0 && buffer->(at+len-6) == 'g' &&
		buffer->(at+len-5) == 'l' && buffer->(at+len-4) == 'i'
		&& buffer->(at+len-3) == 'e')
      	    {
		LTI_Insert(at+len-6, ' ');
                buffer->(at+len-5) = 'a';
                buffer->(at+len-4) = 'l';
                buffer->(at+len-3) = 'u';
                buffer->(at+len-2) = 'i';
                LTI_Insert(at+len-4, ' ');
                x=0; continue;
	    }
	    Tokenise__(buffer,parse);         
            x=0; continue;
	}
    }

! Questa routine è solo per testare se tutto funziona bene. Infatti
! riscrive semplicemente il comando dopo che è stato modificato da
! LanguageToInformese. Per il test dichiarare un Constant INFIT_TEST.
    
#ifdef INFIT_TEST;

    print "[";
    for (x=WORDSIZE:x<WORDSIZE+buffer->(WORDSIZE-1):x++)
	print (char) buffer->x;  
    print  "]^^";

#endif;

];



! =====================================================================
!   Parte IV.  Stampa
! =====================================================================

Constant LanguageAnimateGender   = male;
Constant LanguageInanimateGender = male;

Constant LanguageContractionForms = 3;   


! ---------------------------------------------------------------------
! Qualche regola per gli articoli e una precisazione.
! ---------------------------------------------------------------------
! Ci sono tre casi che dipendono dalla lettera iniziale di una parola:
! 1. Parola che comincia con vocale
! 2. Parola che comincia con z oppure s + consonante (oppure ps, pn,
!    gn, x)
! 3. Parola che comincia con altra consonante.
!
! N.B. Le parole che cominciano con ps, pn, gn e x (molto poche)
!      dovrebbero seguire la regola 2 (secondo la grammatica
!      italiana). Nell'uso reale della lingua si tende a seguire
!      la regola 3. Questa libreria segue la regola grammaticale. Se
!      vuoi cambiarla, per accordarla all'uso reale basta
!      semplicemente specificare l'articolo nella
!      definizione dell'oggetto (has article ""). Per esempio:
!      	    da:  "lo pneumatico, uno pneumatico" (default)
!            a:  "il pneumatico, un pneumatico"  (has article "il")
! --------------------------------------------------------------------- 

[ LanguageContraction text;

	if (text->0 == 'a' or 'e' or 'i' or 'o' or 'u'
		or 'A' or 'E' or 'I' or 'O' or 'U') return 0;
	
	if (text->0 == 'z' or 'Z') return 1;
	
	if (text->0 == 's' or 'S') {
		if (text->1 == 'a' or 'e' or 'i' or 'o' or 'u' 
			or 'A' or 'E' or 'I' or 'O' or 'U') return 2;
		else return 1;
    	}
    
    if (text->0 == 'p' or 'P') {
		if (text->1 == 'n' or 's') return 1;
		else return 2;
    	}
    
	if (text->0 == 'g' or 'G') {
    		if (text->1 == 'n') return 1;
		else return 2;
    	}
    
    return 2;
   
];

Array LanguageArticles -->

!  Contraction form 0:    Contraction form 1:     Contraction form 2:
!  Cdef   Def    Indef    Cdef   Def    Indef     Cdef   Def    Indef

   "L'"   "l'"  "un "     "Lo "  "lo "   "uno "    "Il "  "il "  "un "  
   "L'"   "l'"  "un'"     "La "  "la "   "una "    "La "  "la "  "una "
   
   "Gli " "gli " "degli " "Gli " "gli "  "degli "  "I "   "i "   "dei "  
   "Le "  "le " "delle "  "Le "  "le "   "delle "  "Le "  "le "  "delle ";

                   !             a           i
                   !             s     p     s     p
                   !             m f n m f n m f n m f n               

Array LanguageGNAsToArticles --> 0 1 0 2 3 0 0 1 0 2 3 0;

! ---------------------------------------------------------------------
! Le direzioni della bussola.
! ---------------------------------------------------------------------
[ LanguageDirection d;

	switch(d) {
		n_to: print "nord";
		s_to: print "sud";
		e_to: print "est";
		w_to: print "ovest";
		ne_to: print "nordest";
		nw_to: print "nordovest";
		se_to: print "sudest";
		sw_to: print "sudovest";
		u_to: print "sopra";
		d_to: print "sotto";
		in_to: print "dentro";
		out_to: print "fuori";
		default: return RunTimeError(9,d);
    }

];

! ---------------------------------------------------------------------
! Stampa dei numeri con gestione di alcune forme irregolari. 
! ---------------------------------------------------------------------
[ LanguageNumber n ;

	if (n==0) { 
		print "zero"; 
		rfalse; 
	}
	
	if (n<0) { 
		print "meno "; 
		n=-n; 
	}
	
	if (n>=1000 && n<2000) {
		print " mille"; 
		n=n%1000; 
	}
	
	if (n>=2000 && n<1000000) {
		print (LanguageNumber) n/1000, "mila"; 
		n=n%1000; 
	}
	
	if (n>=100 && n<200) {
		print "cento"; 
		n=n%100;
	}
	
	if (n>=200 && n<1000) {
		print (LanguageNumber) n/100, "cento";
		n=n%100; 
	}
    
    if (n==0) rfalse;
    
    switch(n) {
    		1: print "uno";
    		2: print "due";
		3: print "tre";
		4: print "quattro";
		5: print "cinque";
		6: print "sei";
		7: print "sette";
		8: print "otto";
		9: print "nove";
		10: print "dieci";
		11: print "undici";
		12: print "dodici";
		13: print "tredici";
		14: print "quattordici";
		15: print "quindici";
		16: print "sedici";
		17: print "diciassette";
		18: print "diciotto";
		19: print "diciannove";
		20 to 99: switch(n/10) {
			2: print "vent";
			3: print "trent";
			4: print "quarant";
			5: print "cinquant";
			6: print "sessant";
			7: print "settant";
			8: print "ottant";
			9: print "novant";
     	}
	
		if (n/10 == 2) {
			if (n%10 ~= 1 or 8) print "i";
			if (n%10 ~= 0) print (LanguageNumber) n%10;
		}
		else {
			if (n%10 ~= 1 or 8) print "a";
			if (n%10 ~= 0) print (LanguageNumber) n%10;
		}
		
	}
	
];

! ---------------------------------------------------------------------
! Stampa dell'ora del giorno.
! ---------------------------------------------------------------------

#ifdef ENG_TIME;

[ LanguageTimeOfDay hours mins i;
	i=hours%12; 
    	if (i<10) print " ";
    	if (i==0) i=12;
    	print i, ":", mins/10, mins%10;
    	if ((hours/12) > 0) print " pm"; else print " am";
];

#ifnot;

[ LanguageTimeOfDay hours mins i;
	i=hours%24; 
    	if (i<10) print " ";
    	print i, ":", mins/10, mins%10;
];

#endif;

! ---------------------------------------------------------------------
! Qualche abbreviazione
! ---------------------------------------------------------------------

[ LanguageVerb i;
	if (i == 'g//') { print "guardare"; rtrue; }
	if (i == 'z//') { print "attendre"; rtrue; }
	if (i == 'x//') { print "esaminare"; rtrue; }
	if (i == 'i//' or 'inv' or 'inventario') {
    		print " fare l'inventario"; rtrue;
    	}
    	rfalse;
];


!  Aggiunte queste tre routine per compatibilità con la libreria 6/11
!  Verificare poi per INFIT 3 la possibilità di estenderle.


! ----------------------------------------------------------------------------
!  LanguageVerbIsDebugging è chiamata da SearchScope.  Ritorna true se la 
!  parola w è un verbo di debug che vuole tutti gli oggetti in scope.
! ----------------------------------------------------------------------------

#Ifdef DEBUG;
[ LanguageVerbIsDebugging w;
    if (w == 'purloin' or 'tree' or 'abstract'
                       or 'gonear' or 'scope' or 'showobj')
        rtrue;
    rfalse;
];
#Endif;

! ----------------------------------------------------------------------------
!  LanguageVerbLikesAdverb è chiamata da PrintCommand per gli errori di tipo 
!  UPTO_PE o per messaggi di inferenza.  I verbi intransitivi che richiedono
!  una direzione come avverbio ("vai a est") e non un nome ritornano true.
! ----------------------------------------------------------------------------

[ LanguageVerbLikesAdverb w;
    if (w == 'guarda' or 'vai' or 'spingi' or 'cammina')
        rtrue;
    rfalse;
];

! ----------------------------------------------------------------------------
!  LanguageVerbMayBeName è chiamata da NounDomain rispondendo alla risposta
!  del giocatore alla domanda "Cosa intendi, il bastone corto o il bastone 
!  lungo?" Se la risposta è un altro verbo (esempio: GUARDA) allora la
!  precedente domanda ambigua viene dimenticata a meno che non sia una di 
!  queste parole che possono essere sia un verbo che un aggettivo nella 
!  proprietà name di un oggetto.
! ----------------------------------------------------------------------------

[ LanguageVerbMayBeName w;
    if (w == 'breve' or 'corta' or 'normale'
                    or 'lungo' or 'lunga' or 'completa')
        rtrue;
    rfalse;
];




! ---------------------------------------------------------------------
! Costanti della libreria.
! ---------------------------------------------------------------------

Constant NKEY__TX	= "S = successivo";
Constant PKEY__TX     	= "P = precedente";
Constant QKEY1__TX    	= "  R = riprendi gioco";
Constant QKEY2__TX    	= "R = menu precedente";
Constant RKEY__TX     	= "RETURN = leggi argomento";

Constant NKEY1__KY    	= 'S';
Constant NKEY2__KY    	= 's';
Constant PKEY1__KY    	= 'P';
Constant PKEY2__KY    	= 'p';
Constant QKEY1__KY    	= 'R';
Constant QKEY2__KY    	= 'r';

Constant SCORE__TX    	= "Punti: ";
Constant MOVES__TX    	= "Azioni: ";
Constant TIME__TX     	= "Tempo: ";
Constant CANTGO__TX   	= "Non puoi andare in quella direzione.";
Constant FORMER__TX   	= "quello che eri";
Constant YOURSELF__TX 	= "te stesso";
Constant YOU__TX 		 	= "Tu";
Constant DARKNESS__TX 	= "Oscurit@`a";

Constant THOSET__TX   	= "ci@`o"; 	!"quelle cose";
Constant THAT__TX     	= "ci@`o"; 	!"quello";
Constant OR__TX       	= " oppure ";
Constant NOTHING__TX  	= "niente";
Constant IS__TX       	= " @`e";
Constant ARE__TX      	= " sono";
Constant IS2__TX      	= "c'@`e ";
Constant ARE2__TX     	= "ci sono ";
Constant AND__TX      	= " e ";
Constant WHOM__TX     	= "";
Constant WHICH__TX    	= "";
Constant COMMA__TX	 	= ", ";

! ---------------------------------------------------------------------
! Qualche routine per stampare le parole giuste.
! ---------------------------------------------------------------------
! NOTA 1: 
! Nella definizione degli oggetti basta specificare l'attributo female
! (has female) se l'oggetto è femminile, pluralname (has pluralname)
! se è plurale. Tutti gli altri casi vengono riconosciuti
! automaticamente e si possono usare le routine che seguono senza
! problemi. 
! NOTA 2: 
! (thatorthose) Non è usata nella libreria; L'ho messa per uso dei
! game designer. Tutti i messaggi usano (itorthem), (citorthem) oppure
! (cthatorthose) per indicare gli oggetti.
! ---------------------------------------------------------------------

! (thatorthose): stampa "quello, quella, quelli, quelle"

[ ThatorThose obj;
    if (obj == player) {print "tu"; return; }
    if (obj has pluralname)
    {	if (obj has female) print "quelle"; else print "quelli"; }
    else
    {	if (obj has female) print "quella"; else print "quello"; }
];



! (itorthem): stampa "lo, la, li, le"

[ ItorThem obj;
    if (obj == player) { print "te stesso"; return; }
    if (obj has pluralname)
    {	if (obj has female) print "le"; else print "li"; }
    else
    {	if (obj has female) print "la"; else print "lo"; }
];



! (citorthem): stampa "Lo, La, Li, Le"

[ CItorThem obj;
    if (obj has pluralname)
    {	if (obj has female) print "Le"; else print "Li"; }
    else
    { 	if (obj has female) print "La"; else print "Lo"; }
];



! (cthatorthose): stampa "Quello, Quella, Quelli, Quelle"

[ CThatorThose obj;
    if (obj has pluralname)
    {	if (obj has female) print "Quelle"; else print "Quelli"; }
    else
    {	if (obj has female) print "Quella"; else print "Quello"; }
];



! (isorare): stampa "sono, è" ("sei", se riferito al giocatore)

[ IsorAre obj;
    if (obj == player) print "sei";
    else
	if (obj has pluralname) print "sono"; else print "@`e";
];



! (cisorare): idem, ma in maiuscolo

[ CIsorAre obj;
    if (obj == player) print "Sei";
    else
	if (obj has pluralname) print "Sono"; else print "@`E";
];



! (genderandnumber) stampa la lettera finale per aggettivi e participi
! passati

[ GenderandNumber obj;
    if (obj has pluralname)
    {	if (obj has female) print "e"; else print "i"; }
    else
    {	if (obj has female) print "a"; else print "o"; }
];



! (whomorwhich1) e (whomorwhich2) stampa la forma corretta di pronomi
! relativi. Sono usate al posto delle costanti WHOM_TX e WHICH_TX che
! ho invece dichiarato come stringhe vuote. Sono usate nei messaggi
! ListMiscellany 19, 20, 21 e 22.

[ WhomorWhich1 obj;
    if (obj has pluralname)
    {	if (obj has female) print "lle quali"; else print "i quali"; }
    else
    {	if (obj has female) print "lla quale"; else print "l quale"; }
];

[ WhomorWhich2 obj;
    if (obj has pluralname)
    {	if (obj has female) print "le quali"; else print "i quali"; }
    else
    {	if (obj has female) print "la quale"; else print "il quale"; }
];



! Stampa delle preposizioni articolate
! Modificato per renderlo compatibile con GLULX

[ Articolo o pluralise i;

    #Ifdef TARGET_ZCODE;
    StorageForShortName-->0 = 160;
    @output_stream 3 StorageForShortName;
    if (pluralise) print (number) pluralise; else print (PSN__) o;
    @output_stream -3;
    #Ifnot; ! TARGET_GLULX
    if (pluralise)
	PrintAnyToArray(StorageForShortName, 160, EnglishNumber, pluralise);
    else
	PrintAnyToArray(StorageForShortName, 160, PSN__, o);
    #Endif; ! TARGET_

    
    if ((o has pluralname) && (o hasnt female))
    {
	print (the) o;
	return;
    } 
    else
    {
	print "l";
	i = LanguageContraction(StorageForShortName + 2);
	if ((i == 2) && (o hasnt female))
	{
	    print " ", (name) o;
	    return; 
	}
	else 
	{
	    print (the) o;
	}
    }

];

[ ArtDa o i;
    print "da";
    i = indef_mode; indef_mode = false;
    if (o has proper)
    { indef_mode = NULL; print " ", (PSN__) o; indef_mode = i; return; }
    Articolo(o); indef_mode = i;
];

[ ArtSu o i;
    print "su";
    if ( o == player ) { print " di te"; rfalse; }
    i = indef_mode; indef_mode = false;
    if (o has proper)
    { indef_mode = NULL; print " ", (PSN__) o; indef_mode = i; return; }
    Articolo(o); indef_mode = i;
];

[ ArtIn o i;
    if ( o == player ) print "in ";
    else print "ne";
    i = indef_mode; indef_mode = false;
    if (o has proper)
    { indef_mode = NULL; print " ", (PSN__) o; indef_mode = i; return; }
    Articolo(o); indef_mode = i;
];

[ ArtA o i;
    print "a";
    i = indef_mode; indef_mode = false;
    if (o has proper)
    { indef_mode = NULL; print " ", (PSN__) o; indef_mode = i; return; }
    Articolo(o); indef_mode = i;
];

[ ArtDi o i;
    if ( o == player )
    { print "di te"; return; }
    print "de";
    i = indef_mode; indef_mode = false;
    if (o has proper)
    { indef_mode = NULL; print " ", (PSN__) o; indef_mode = i; return; }
    Articolo(o); indef_mode = i;
];



! PrintPrep() e PrintInfinitive() sostituiscono nei messaggi Miscellany
! #48 & #49 la routine del parser PrintCommand(). Esse stampano la preposizione
! e la corretta forma di infinito per ogni verbo dato come comando.
! PrintInfinitive() gestisce anche alcune forme irregolari.

Global verb_flag = false;
Global verb_acc = THOSET__TX;
!Array prepos --> 51;

[ PrintPrep i j k prep_flag p;

        
    for (k=1:k<pcount:k++)
    {
	i=pattern-->k;
        if (i==PATTERN_NULL) continue;
        if (prep_flag) print (char) ' ';
      	if (i==0)
      	{
	    !print (string) THOSET__TX;
	    verb_flag = true;
	    verb_acc = THOSET__TX;
	    jump PrepOK;
	    
      	}
      	if (i==1)
      	{
	    !print (string) THAT__TX;
	    verb_flag = true;
	    verb_acc = THAT__TX;
	    jump PrepOK;
      	}
        if (i>=REPARSE_CODE)
        {
	    
	    ! Per Glulx utilizzo PrintToBuffer. Questa routine sembra avere problemi in 
	    ! z-code con gli indirizzi di parole nel dizionario mentre PrintAnyToArray non 
	    ! memorizza la lunghezza in "-->0" quindi avrei dovuto duplicare anche il restante
	    ! codice.

	    #Ifdef TARGET_ZCODE;
	    StorageForShortName-->0 = 160;
	    @output_stream 3 StorageForShortName;
	    print (address) No__Dword(i - REPARSE_CODE);
	    @output_stream -3;
	    #Ifnot; ! TARGET_GLULX
	    PrintToBuffer(StorageForShortName, 160, No__Dword(i - REPARSE_CODE));
	    #Endif; ! TARGET_

	    p = StorageForShortName->WORDSIZE;

	    if (p=='i')
	    {
		print "Dentro";		 	
		prep_flag = true;	
		jump PrepOk;		
	    }

	    ! Risolve il bug con "fai vedere". La parola vedere era
	    ! infatti riconosciuta come preposizione e veniva stampato
	    ! qualcosa del genere "Vedere cosa vuoi fare?". Nel caso
	    ! la "preposizione" non è vedere converte l'iniziale in
	    ! maiuscolo.

	    ! MODIFICATA: Uilizza la routine UpperCase per convertire
	    ! in maiuscolo (vale anche in Glulx). Ho cambiato anche
	    ! gli estremi del ciclo for utilizzando WORDSIZE.
 	    
	    if (p<'v')		    
	    {			    
		if (p >= 'a' && p <= 'z')
		{             
		    p = UpperCase(p);    
		};
		print (char) p;
		
		for (j=WORDSIZE+1: j<(StorageForShortName-->0)+WORDSIZE: j++) print (char) StorageForShortName->j;
		prep_flag = true;
		jump PrepOk;
	    }
	}
	else verb_acc = i;
    }
    
    .PrepOk;
    if (prep_flag==false) print "C";
    if (prep_flag==true ) print " c";

];

[ PrintInfinitive i n l t x j;
    i=verb_word;
    n = verb_wordnum;
    l=WordLength(n);
    t=WordAddress(n);

    
    if (t->0 == 'b' &&
 	t->1 == 'e' &&
 	t->2 == 'v' &&
 	t->3 == 'i')
    {   print "bere";
	jump Accusative;
    }
    if (t->0 == 'd' &&
 	t->1 == 'i')
    {	print "dire";
 	jump Accusative;
    }
    if (t->0 == 'd' &&
 	t->1 == 'a' &&
 	t->2 == 'l' &&
 	t->3 == 'l')
    {	print "dare";
	jump Accusative;
    }
    if (t->0 == 'x') !! && t->1 == 0)
    {	print "esaminare";
 	jump Accusative;
    }
    if (t->0 == 'l' or 'g' && t->1 == 0)
    {	print "guardare";
 	jump Accusative;
    }
    if (t->0 == 'f' &&
 	t->1 == 'a' &&
 	t->2 == 'i' &&
 	t->3 == ' ' &&
 	t->4 == 'v' &&
 	t->5 == 'e' &&
 	t->6 == 'd')
    {	print "far vedere";
 	jump Accusative;
    }
    if (t->0 == 'f' &&
 	t->1 == 'a' &&
 	t->2 == ' ' &&
 	t->3 == 'v' &&
 	t->4 == 'e' &&
 	t->5 == 'd')
    {	print "far vedere";
 	jump Accusative;
    }
    if (t->0 == 's' &&
 	t->1 == 'a' &&
 	t->2 == 'l' &&
 	t->3 == 'i')
    {	print "salire";
 	jump Accusative;
    }
    if (t->0 == 'a' &&
 	t->1 == 'r' &&
 	t->2 == 'r' &&
 	t->3 == 'a' &&
 	t->4 == 'm')
    {	print "arrampicarti";
 	jump Accusative;
    }
    
    if (t->0 == 'v' &&
 	t->1 == 'a' &&
 	t->2 == 'i')
    {	print "andare";
 	jump Accusative;
    }
    if (t->(l-1) == 'i' &&
 	t->(l-2) == 'l' &&
 	t->(l-3) == 'g')
    { 	print (address) i;
 	print "ere";
 	jump Accusative;
    }    
    if (t->0 == 's' &&
 	t->1 == 'i' &&
 	t->2 == 'e')
    {	print "sederti";
 	jump Accusative;
    }
    if (t->0 == 's' && 
 	t->1 == 'd' && 
 	t->2 == 'r')
    {	print "sdraiarti";
 	jump Accusative;
    }
    if (t->(l-1) == 'a')
    {	print (address) i;
 	print "re";
 	jump Accusative;
    }
    if (t->(l-1) == 'i' &&
 	t->(l-2) == 'c' &&
 	t->(l-3) == 's')
    {	t->(l-3) = 'r';
 	t->(l-2) = 'e';
 	t->(l-1) = ' ';
 	for (x=0: x<l: x++) print (char) t->x;
 	t->(l-3) = 's';
 	t->(l-2) = 'c';
 	t->(l-1) = 'i';
 	jump Accusative;
    }
    if (t->(l-1) == 'i' &&
 	t->(l-2) == 'r' &&
 	t->(l-3) == 'p' or 'f')
    {	print (address) i;
 	print "re";
 	jump Accusative;
    }
    if (t->(l-1) == 'i' &&
 	t->(l-2) == 'a')
    {	j = t->(l-1);
 	t->(l-1) = 'r';
 	for (x=0: x<l: x++) print (char) t->x;
 	print "e";
 	t->(l-1) = j;
 	jump Accusative;
    }
    else
    {
	j = t->(l-1);
	t->(l-1) = 'e';
	for (x=0: x<l: x++) print (char) t->x;
	print  "re";
	t->(l-1) = j;
	jump Accusative;
    }
    
    .Accusative;
    if (verb_flag == true)
    {	print " ";
 	print (string) verb_acc;
 	!if (acc_bit == 1) {print (string) THAT__TX;}
 	!if (acc_bit == 2) {print (string) THOSET__TX;}
 	!else print "ERRORE!!!";
    }

  
];



! ---------------------------------------------------------------------
! Messaggi della libreria
! ---------------------------------------------------------------------

[ LanguageLM n x1;

	Answer, Ask: "Nessuna risposta.";
    !   Ask: (vedi Answer)
    	Attack: "La violenza non @`e la giusta risposta a questo.";
    	Blow: "Non c'@`e niente di utile nel soffiare ", (artsu) x1, ".";
    	Burn: "Con questo atto pericoloso non concluderai niente.";
    	Buy: "Non c'@`e niente in vendita.";
    	Climb: "Non penso si possa raggiungere qualcosa da qui.";
    	Close: switch (n) {
		1: "Non puoi chiudere ", (the) x1;
		2: print_ret (cisorare) x1, " gi@`a chius", (genderandnumber) x1, ".";
		3: "Hai chiuso ", (the) x1, ".";
    	}
   	CommandsOff: switch (n) {
   		1: "[Registrazione dei comandi disattivata.]";
   		#Ifdef TARGET_GLULX;
   		2: "[Registrazione dei comandi gi@`a disattivata.]";
   		#Endif;
	}
	CommandsOn: switch (n) {
    		1: "[Registrazione dei comandi attivata.]";
		#Ifdef TARGET_GLULX;
    		2: "[La riproduzione dei comandi @`e attiva proprio in questo momento.]";
		3: "[Registrazione dei comandi gi@`a attiva.]";
		4: "[Errore nella registrazione dei comandi.]";	
		#Endif;
	}
    	CommandsRead: switch(n) {
    		1: "[Riproduzione dei comandi registrati.]";
      	#Ifdef TARGET_GLULX;
      	2: "[I comandi registrati sono gi@`a stati riprodotti.]";
		3: "[Errore nella riproduzione dei comandi registrati. La registrazione dei comandi @`e attiva.]";
		4: "[Errore nella riproduzione dei comandi registrati.]";
		5: "[La riproduzione dei comandi registrati @`e stata completata.]";
		#Endif;
	}
	Consult: "Non hai scoperto niente di interessante, consultando ", (the) x1, ".";
    	Cut: "Tagliar", (itorthem) x1, " a pezzi servir@`a a poco.";
    	Dig: "Scavare non serve a niente qui.";
    	Disrobe: switch(n) {
    		1: "Non ", (itorthem) x1, " stai indossando.";
		2: "Ti sei tolto ", (the) x1, ".";
   	}
    	Drink: "Non c'@`e niente che puoi bere qui.";
    	Drop: switch(n) {
    		1: print_ret (The) x1, " ", (isorare) x1, " gi@`a posat", (genderandnumber) x1, " qui.";
    		2: "Non possiedi ", (thatorthose) x1, ".";
        	3: "(Prima ti togli ", (the) x1, ")";
        	4: "Posat", (genderandnumber) x1, ".";
    	}
    	Eat: switch(n) {
    		1: if (x1 has pluralname) print_ret (cisorare) x1, " praticamente immangiabili.";
    		   else print_ret (cisorare) x1, " praticamente immangiabile.";
		2: "Mangi ", (the) x1, ". Niente male.";
    }
    	EmptyT: switch(n) {
       	1: if (x1 has pluralname) print_ret (The) x1, " non sono contenitori.";
       	   else print_ret (The) x1, " non @`e un contenitore.";
       	2: print_ret (The) x1, " ", (isorare) x1, " chius", (genderandnumber) x1, ".";
       	3: print_ret (The) x1, " ", (isorare) x1, " gi@`a vuot", (genderandnumber) x1, ".";
       	4: "Probabilmente in questo modo non svuoteresti nulla.";
    	}
    	Enter: switch(n) {
		1: print "Ma gi@`a sei ";
		   if (x1 has supporter) print "sopra "; else print "dentro ";
	    	   print_ret (the) x1, ".";
		2: if (x1 has pluralname) print "Non sono"; else print "Non @`e";
	   	   print " qualcosa ";
	   	   switch (verb_word) {
	       	'stai': "su cui poter stare.";
	       	'sta': "su cui poter stare.";
	       	'sdraiati': "su cui ti puoi sdraiare.";
	       	'siediti': "su cui ti puoi sedere.";
	       	'siedi': "su cui ti puoi sedere.";
	       	default: "in cui puoi entrare.";
	   	   }
		3: "Non puoi entrare dentro ", (the) x1, ". ", (cisorare) x1, " chius", (genderandnumber) x1, ".";
		4: "Puoi entrare solo in qualcosa di libero.";
		5: print "Ti trovi ";
	   	   if (x1 has supporter) print "sopra "; else print "dentro ";
	    	   print_ret (the) x1, ".";
		6: print "(ti togli da ";
	   	   if (x1 has supporter) print "sopra "; else print "dentro ";
	   	   print (the) x1; ")";
	 	7: if (x1 has supporter) "(sali sopra ", (the) x1, ")^";
	   	   if (x1 has container) "(entri dentro ", (the) x1, ")^";
	   	   "(entri dentro ", (the) x1, ")^";
    	}  
   	Examine: switch(n) {
		1: "Oscurit@`a, sost. femminile. Assenza della luce necessaria per vedere. Buio. Tenebre.";
		2: "Esamini ", (the) x1, ", ma non noti niente di speciale.";
		3: print (The) x1, " ", (isorare) x1;
		   if (x1 has on) " acces", (genderandnumber) x1, ".";
	       else " spent", (genderandnumber) x1, ".";
    	}
    	Exit: switch(n) {
		1: "E da dove? Dovresti spiegarti meglio.";
		2: "Non puoi uscire fuori, ", (the) x1, " ", (isorare) x1, " chius", (genderandnumber) x1, ".";
		3: print "Sei ";
	   	   if (x1 has supporter) print "sceso "; else print "uscito ";
	   	   print_ret (artda) x1, ".";
		4: print "Cosa? Non sei ";
	    	   if (x1 has supporter) print "sopra "; else print "dentro ";
        	   print_ret (the) x1, ".";
    }
    	Fill: "Ma non c'@`e acqua qui da trasportare.";
    	FullScore: switch(n) {
		1: if (deadflag) print "Il punteggio era ";
	   	   else print "Il punteggio @`e ";
	   	   "cos@`i composto:^";
		2: "in vari oggetti trovati";
		3: "visitando vari luoghi";
		4: print "in totale (su ", MAX_SCORE; " possibili)";
    	}
    	GenericVerb: "Cosa vuoi fare? Potresti essere pi@`u preciso?";
    	GetOff: "Ma non sei sopra ", (the) x1, " in questo momento.";
    	Give: switch(n) {
		1: "Non possiedi ", (the) x1, ".";
		2: "Vuoi dare ", (the) x1, " a te stesso? Non ti seguo.";
		3: print (The) x1;
	   	   if (x1 has pluralname) print " non sembrano";
	   	   else print " non sembra";
	   	   " interessat", (genderandnumber) x1, ".";
    	}
    	Go: switch(n) {
		1: print "Dovresti toglierti da ";
	   	   if (x1 has supporter) print "sopra "; else print "dentro ";
	   	   print_ret (the) x1, " prima.";
		2: print_ret (string) CANTGO__TX; ! "Non puoi andare in quella direzione.";
		3: "Non riesci a salire sopra ", (the) x1, ".";
		4: "Non riesci a scendere da sopra ", (the) x1, ".";
		5: "Non puoi, ", (the) x1, " ", (isorare) x1, " in quella direzione.";
		6: print "Non puoi, ", (the) x1;
	   	   if (x1 has pluralname) print " non conducono ";
	   	   else print " non conduce ";
	   	   "da nessuna parte.";
    	}
    	Insert: switch(n) {
		1: "@`E necessario che tu possieda ", (the) x1, " prima di poterl", 
		   (genderandnumber) x1, " mettere dentro ", (the) second, ".";
		2: if (x1 has pluralname) print_ret (Cthatorthose) x1, " non sono contenitori.";
	   	   else print_ret (Cthatorthose) x1, " non @`e un contenitore.";
		3: print_ret (The) x1, " ", (isorare) x1, " chius", (genderandnumber) x1, ".";
		4: "Sar@`a necessario che tu ", (itorthem) x1, " lasci prima.";
		5: "Non puoi mettere una cosa dentro se stessa.";
		6: "(prima ", (itorthem) x1, " lasci)^";
		7: "Non c'@`e pi@`u spazio dentro ", (the) x1, ".";
		8: "Fatto.";
		9: "Hai messo ", (the) x1, " dentro ", (the) second, ".";
    	}
   	Inv: switch(n) {
		1: "Non stai portando niente.";
		2: print "Stai portando";
		3:  print ":^";
		4:  print ".^";
    	}
    	Jump: "Salti sul posto, senza risultato.";
   	JumpOver, Tie: "Non raggiungerai niente con questo.";
   	Kiss: "Concentrati sul gioco.";
    	Listen: "Non si sente niente di particolare.";
    	ListMiscellany: switch(n) {
    		1: print " (acces", (genderandnumber) x1, ")";
		2: print " (che ", (isorare) x1, " chius", (genderandnumber) x1, ")";
		3: print " (chius", (genderandnumber) x1, " e acces", (genderandnumber) x1, ")";
		4: print " (che ", (isorare) x1, " vuot", (genderandnumber) x1, ")";
		5: print " (vuot", (genderandnumber) x1, " e acces", (genderandnumber) x1, ")";
		6: print " (che ", (isorare) x1, " chius", (genderandnumber) x1, " e vuot", (genderandnumber) x1, ")";
		7: print " (chius", (genderandnumber) x1, ", vuot", (genderandnumber) x1, " e acces", (genderandnumber) x1, ")";
		8: print " (acces", (genderandnumber) x1, " e  indossat", (genderandnumber) x1, ")";
		9: print " (acces", (genderandnumber) x1;
		10: print " (indossat", (genderandnumber) x1;
		11: print " (che ", (isorare) x1, " ";
		12: print "apert", (genderandnumber) x1;
		13: print "apert", (genderandnumber) x1, " ma vuot", (genderandnumber) x1;
		14: print "chius", (genderandnumber) x1;
		15: print "chius", (genderandnumber) x1, " a chiave";
		16: print " e vuot", (genderandnumber) x1;
		17: print " (che ", (isorare) x1, " vuot", (genderandnumber) x1, ")";
		18: if (x1 has pluralname) print " che contengono ";
	   	    else print " che contiene ";
		19: print " (su", (whomorwhich1) x1, " ";
		20: print ", sopra ", (whomorwhich2) x1, " ";
		21: print " (ne", (whomorwhich1) x1, " ";
		22: print ", dentro ", (whomorwhich2) x1, " ";
    	}
    	LMode1: " @`e ora in modalit@`a ~normale~, che d@`a descrizioni
            lunghe per i luoghi mai visitati prima e brevi se gi@`a
            visitati.";
   	LMode2: " @`e ora in modalit@`a ~completa~, che d@`a descrizioni
            lunghe per tutti i luoghi (anche se gi@`a visitati).";
   	LMode3: " @`e ora in modalit@`a ~breve~, che d@`a descrizioni
            brevi per tutti i luoghi (anche se mai visitati).";
    	Lock: switch(n) {
		1: if (x1 has pluralname) print "Non sembrano ";
	   	   else print "Non sembra ";
	   	   "essere qualcosa che possa essere chiusa a chiave.";
		2: print_ret (cisorare) x1, " chius", (genderandnumber) x1, " a chiave in questo momento.";
		3: "Prima dovresti chiudere ", (the) x1, ".";
		4: if (x1 has pluralname) print "Non sembrano ";
	   	   else print "Non sembra ";
	   	   "entrare nella serratura.";
		5: "Ora hai chiuso a chiave ", (the) x1, ".";
    	}
    	Look: switch(n) {
		1: print " (sopra ", (the) x1, ")";
		2: print " (dentro ", (the) x1, ")";
		3: print " (come ", (object) x1; print ")";
		4: print "^Sopra ", (the) x1, " vedi ";
	   	   WriteListFrom(child(x1), ENGLISH_BIT + RECURSE_BIT + 
	   	   		FULLINV_BIT + TERSE_BIT + CONCEAL_BIT);
	   	   ".";
		5,6:	if (x1~=location) {
				if (x1 has supporter) print "^Sopra ";
				else print "^Dentro ";
				print (the) x1, " puoi";
	    		}
	    		else print "^Puoi";
	    		if (n==5) print " anche";
 	    		print " vedere ";
	    		WriteListFrom(child(x1), ENGLISH_BIT + WORKFLAG_BIT +
				RECURSE_BIT + PARTINV_BIT + TERSE_BIT + CONCEAL_BIT);
	    		if (x1~=location) ".";
	    		" qui.";
		7: "Non vedi niente di strano in quella direzione.";
    	}
    	LookUnder: switch(n) {
		1: "Ma @`e buio.";
		2: "Non trovi niente di interessante.";
    	}
    	Mild: "Proprio cos@`i.";
    	Miscellany: switch(n) {
        	1: "(considero solo i primi sedici oggetti)^";
		2: "Niente da fare!";
		3: print " Sei morto ";
		4: print " Hai vinto ";
		5: print "^Vuoi RICOMINCIARE, CARICARE una partita salvata";
		   #Ifdef DEATH_MENTION_UNDO;
	   	   print ", ANNULLARE il tuo ultimo comando";
        	   #Endif;
	   	   if (TASKS_PROVIDED==0) print ", avere il punteggio COMPLETO della partita";
	   	   if (deadflag==2 && AMUSING_PROVIDED==0) print ", avere suggerimenti per cose DIVERTENTI da fare";
        	   " o USCIRE ?";
        	6: "[L'interprete non pu@`o gestire il comando ~cancella~.]";
            #Ifdef TARGET_ZCODE;
		7: "~Cancella~ non ha funzionato. [Non tutti gli interpreti lo
	    	   supportano.]";
            #Ifnot; ! TARGET_GLULX
        	7:  "[Non puoi pi@`u cancellare i comandi.]";
            #Endif; ! TARGET_        	
		8: "Per favore, dai una delle risposte elencate.";
		9: "^@`E completamente buio qui!";
		10: "Scusa!!??";
		11: "[Non puoi cancellare ci@`o che non hai fatto!]";
		12: "[Non puoi cancellare due volte di seguito. Spiacente!]";
		13: "[Azione precedente cancellata.]";
		14: "Spiacente, questo non pu@`o essere corretto.";
		15: "Non c'@`e di che.";
		16: "Il comando ~oops~ pu@`o correggere solo una parola.";
		17: "@`E completamente buio, e non riesci a vedere niente.";
		18: print "te stesso";
		19: "Hai sempre lo stesso bell'aspetto.";
		20: "Per ripetere un comando come ~rana, salta~, basta solamente ~ancora~, non ~rana, ancora~.";
		21: "Difficilmente potrai ripetere quello che hai appena fatto.";
		22: "Non puoi iniziare un comando con una virgola.";
		23: "Sembra che tu voglia parlare con qualcuno, ma non capisco con chi.";
		24: "Non puoi parlare con ", (the) x1, ".";
		25: "Per parlare a qualcuno prova ~qualcuno, ciao~ o qualcosa di simile.";
		26: "(prima prendi ", (the) not_holding, ")";
		27: "Cosa vuoi dire? Non riesco a capire.";
		28: print "Ho capito la frase solo fino a: ";
		29: "Non riesco a capire il numero.";
		30: "Non vedi nulla del genere.";
		31: "Mi sembra che tu abbia detto troppo poco!";
		32: "Non possiedi questa cosa!";
		33: "Non puoi usare oggetti multipli con quel verbo.";
		34: "Puoi usare oggetti multipli solo una volta per comando.";
		35: "Non riesco a capire a cosa ~", (address) pronoun_word, "~ si riferisca.";
		36: "Non puoi escludere qualcosa che non hai incluso!";
		37: "Hey! Puoi farlo solo con esseri viventi.";
		38: "Questo @`e un verbo che non conosco.";
		39: "Non @`e importante ai fini del gioco.";
		40: "(", (the) pronoun_obj, ")^Non ", (itorthem) pronoun_obj, " vedi.";
		41: "Non ho capito la fine del comando.";
		42: if (x1==0) print "Nessuno";
	   	    else print "Solamente ", (number) x1;
	    	    print " ne ";
	    	    if (x1==1 || x1==0) { print "@`e disponibile.^";}
	   	    else print "sono disponibili.^";
		43: "Niente da fare!";
		44: "Non ce ne sono di disponibili!";
		45: print "Chi intendi, ";
		46: print "Cosa intendi, ";
		47: print "Spiacente, ne puoi avere solo uno. Quale esattamente?";
		48: PrintPrep(); print "hi ";
	    		if (actor==player) { print "vuoi "; PrintInfinitive(); }
	    		else {
				print "dovrebbe";
				if (actor has pluralname) print "ro";
				print " ";
				PrintInfinitive();
				print " ", (the) actor;
	    		}
	    		print "?^";
		49: PrintPrep(); print "osa ";
	    		if (actor==player) { print "vuoi "; PrintInfinitive(); }
	    		else {
				print "dovrebbe";
				if (actor has pluralname) print "ro";
				print " ";
				PrintInfinitive();
				print " ", (the) actor;
	    		}
	    		print "?^";
		50: print "Il tuo punteggio @`e appena ";
	    	    if (x1 > 0) print "aumentato";
	    	    else { x1 = -x1; print "diminuito"; }
	    	    print " di ";
	    	    if (x1 == 1) print "un punto";
	    	    if (x1 > 1) print (number) x1, " punti";
		51: "(@`E accaduto qualcosa di drammatico, i comandi disponibili sono stati ridotti.)";
		52: "^Inserisci un numero da 1 a ", x1, ", 0 per rivedere o premi INVIO.";
		53: "^[Per favore premi SPAZIO.]";
        	54: "[Il tuo commento @`e stato annotato.]";
        	55: "[Attenzione: la TRASCRIZIONE non @`e attiva.]";
        	56: print ".^";
        	57: print "?^";
    	}
   	No, Yes: "Era una domanda retorica.";
    	NotifyOff: "Notifica del punteggio disattivata.";
    	NotifyOn: "Notifica del punteggio attivata.";
    	Objects: switch(n) {
        	1: "Oggetti posseduti:^";
		2: "Nessuno.";
		3: print "   (indossat", (genderandnumber) x1, ")";
		4: print "   (in tuo possesso)";
		5: print "   (dat", (genderandnumber) x1, " via)";
		6: print "   (si trova ", (name) x1, ")";
		7: print "   (ne", (whomorwhich1) x1, " ", (name) x1, ".)";
		8: print "   (dentro ", (the) x1, ")";
		9: print "   (sopra ", (the) x1, ")";
		10: print "   (pers", (genderandnumber) x1, ")";
    	}
    Open: switch(n) {
        	1: "Non puoi aprire ", (the) x1, ".";
		2: if (x1 has pluralname) print "Sembrano ";
	   	   else print "Sembra ";
	   	   "essere chius", (genderandnumber) x1, " a chiave.";
		3: print_ret (cisorare) x1, " gi@`a apert", (genderandnumber) x1, ".";
		4: print "Hai aperto ", (the) x1, ", trovando ";
	   	   if (WriteListFrom(child(x1),ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT)==0) "un bel nulla.";
	   	   ".";
		5: "Ora hai aperto ", (the) x1, ".";
    	}
    	
    	Order: print (The) x1; 
           if (x1 has pluralname) print " hanno"; 
	   else print " ha";
	   " altre cose da fare.";
    Places: print "Hai gi@`a visitato: ";
    Pray: "Sembra che le tue preghiere non siano state esaudite.";
    Prompt:
    #ifdef PROMPT; 
	switch(random(15)) {
        1: print "^Adesso?";
	2: print "^E adesso?";
	3: print "^Allora?";
	4: print "^Ora?";
	5: print "^E ora?";
	6: print "^Quindi?";
	7: print "^Che si fa?";
	8: print "^Che suggerisci di fare?";
	9: print "^Che dici di fare?";
	10: print "^E ora che si fa?";
	11: print "^Cosa devo fare ora?";
	12: print "^S@`i?";
	13: print "^Poi?";
	14: print "^Dimmi:";
	15: print "^Aspetto un tuo comando:";
    }
    #endif;
	print "^>";
    Pronouns: switch(n) {
	1: print "Al momento, ";
	2: print "significa ";
	3: print "@`e disattivato";
	4: "nessun pronome @`e conosciuto dal gioco.";
    }
    Pull, Push, Turn: switch(n) {
	1: print "", (cisorare) x1, " fiss", (genderandnumber) x1,
	    " al ";
	   if (x1 has pluralname) print "loro";
	   else print "suo";
	   " posto.";
	2: "Non sei capace di farlo.";
	3: "Non succede niente di particolare.";
	4: "Questo sarebbe meno che cortese.";
    }
    ! Pull: (vedi Push)
    PushDir: switch(n) {
	1: "Questo @`e il meglio che ti viene in mente?";
	2: "Non @`e una direzione.";
	3: "Non puoi in quella direzione.";
    }
    PutOn: switch(n) {
	1: "@`E necessario che tu possieda ", (the) x1, " prima di
	    poterl", (genderandnumber) x1, " mettere sopra ", 
	    (the) second, ".";
	2: "Non puoi mettere qualcosa su se stessa.";
	3: "Mettere cose sopra ", (the) x1, " non porter@`a a niente.";
	4: "Manchi di destrezza.";
	5: "(prima ", (itorthem) x1, " lasci)^";
	6: "Non c'@`e pi@`u spazio sopra ", (the) x1, ".";
	7: "Fatto.";
	8: "Hai messo ", (the) x1, " sopra ", (the) second, ".";
    }
    Quit: switch(n) {
	1: print "Per favore, rispondi SI o NO.";
	2: print "Sei sicuro di voler uscire? ";
    }
    Remove: switch(n) {
	1: if (x1 has pluralname) print "Sono ";
	   else print "@`E ";
	   " chius", (genderandnumber) x1, ".";
	2: if (x1 has pluralname) print "Ma non sono";
	   else print "Ma non @`e";
	   " l@`i ora.";
	3: "Rimoss", (genderandnumber) x1, ".";
    }
    Restart: switch(n) {
	1: print "Sei sicuro di voler ricominciare? ";
	2: "Tentativo fallito.";
    }
    Restore: switch(n) {
	1: "Caricamento fallito.";
	2: "Ok.";
    }
    Rub: "Non otterrai niente con questo.";
    Save: switch(n) {
	1: "Salvataggio della partita fallito.";
	2: "Ok.";
    }
    Score: if (deadflag) print "In questa partita hai totalizzato ";
	   else print "Finora hai totalizzato ";
	   print score;
	   if (score == 1) print " punto"; else print " punti";
	   print " su ", MAX_SCORE, " possibili, in ", turns, " turn";
	   if (turns == 1) print "o"; else print "i";
	   return;
    ScriptOff: switch(n) {
	1: "La trascrizione @`e gi@`a disattivata.";
	2: "^Fine della trascrizione.";
	3: "@`E fallito il tentativo di terminare la trascrizione";
    }
    ScriptOn: switch(n) {
	1: "La trascrizione @`e gi@`a attivata.";
	2: "Inizio della trascrizione di ";
	3: "@`E fallito il tentativo di iniziare la trascrizione.";
    }
    Search: switch(n) {
	1: "Ma @`e buio.";
	2: "Non c'@`e niente sopra ", (the) x1, ".";
	3: print "Sopra ", (the) x1, " vedi ";
	   WriteListFrom(child(x1), TERSE_BIT + ENGLISH_BIT +
		CONCEAL_BIT);
	   ".";
	4: "Non hai trovato niente di interessante.";
	5: "Non puoi guardare dentro, perch@'e ", (the) x1, " ",
	    (isorare) x1, " chius", (genderandnumber) x1, ".";
	6: print_ret (The) x1, " ", (isorare) x1, " vuot",
	    (genderandnumber) x1, ".";
	7: print "Dentro ", (the) x1, " vedi ";
	   WriteListFrom(child(x1), TERSE_BIT + ENGLISH_BIT + 
		CONCEAL_BIT);
	   ".";
    }
    Set: "No, non puoi metter", (itorthem) x1, ".";
    SetTo: "No, non puoi impostarl", (itorthem) x1, " a nulla.";
    Show: switch(n) {
	1: "Non possiedi ", (the) x1, ".";
	2: print (The) x1;
	   if (x1 has pluralname) print " non sembrano";
	   else print " non sembra";
	   " interessat", (genderandnumber) x1, ".";
    }
    Sing: "Sei stonatissimo.";
    Sleep: "Non sei per niente assonnato.";
    Smell: "Non senti alcun odore particolare.";
    Sorry: "Oh, non scusarti.";
    Squeeze: switch(n) {
	1: "Tieni a posto le mani.";
	2: "Non hai ottenuto niente con questo.";
    }
    Strong: "I veri avventurieri non usano un simile linguaggio.";
    Swim: "Non c'@`e abbastanza acqua in cui poter nuotare.";
    Swing: "Non c'@`e niente da poter scuotere qui.";
    SwitchOff: switch(n) {
	1: "Non puoi spegnere ", (the) x1, ".";
	2: print_ret (cisorare) x1, " gi@`a spent",
	    (genderandnumber) x1, ".";
	3: "Hai spento ", (the) x1, ".";
    }
    SwitchOn: switch(n) {
	1: "Non puoi accendere ", (the) x1, ".";
	2: print_ret (cisorare) x1, " gi@`a acces",
	    (genderandnumber) x1, ".";
	3: "Hai acceso ", (the) x1, ".";
    }
    Take: switch(n) {
	1: "Pres", (genderandnumber) noun, ".";
	2: "Sei sempre il possessore di te stesso.";
	3: print "Non credo che ", (the) x1, " abbia";
	   if (x1 has pluralname) print "no";
	   " intenzione di farsi prendere in braccio.";
	4: print "Dovresti toglierti da ";
	   if (x1 has supporter) print "sopra "; else print "dentro ";
	   print_ret (the) x1, " prima.";
	5: "Gi@`a l", (genderandnumber) x1, " possiedi.";
	6: if (noun has pluralname) print "Sembrano appartenere ";
	   else print "Sembra che appartenga ";
	   print_ret (arta) x1, ".";
	7: if (noun has pluralname) print "Sembrano ";
	   else print "Sembra ";
	   "essere parte ", (artdi) x1, ".";
	8: if (x1 has pluralname) print_ret (Cthatorthose) x1,
	     " non sono disponibili.";
	   else print_ret (Cthatorthose) x1,
	     " non @`e disponibile.";
	9: print (The) x1, " non  ", (isorare) x1, "apert",
	     (genderandnumber) x1, ".";
	10: print (The) x1;
	    if (x1 has pluralname) print_ret " sono difficilmente
	      trasportabili.";
	    else print_ret " @`e difficilmente trasportabile.";
	11: if (x1 has pluralname) print_ret "Sono fiss",
	      (genderandnumber) x1, " al loro posto.";
	    else print_ret "@`E fiss", (genderandnumber) x1, " al suo
	      posto.";
	12: "Stai trasportando gi@`a troppe cose.";
	13: "(metti ", (the) x1, " dentro ", (the) SACK_OBJECT, " per
	      fare spazio)";
    }
    Taste: "Nessun sapore particolare.";
    Tell: switch(n) {
	1: "Stai parlando a te stesso.";
	2: "Proprio nessuna reazione.";
    }
    Think: "Questa s@`i che @`e una buona idea.";
    ThrowAt: switch(n) {
	1: "Senza successo.";
	2: "Nel momento cruciale ti manca il coraggio.";
    }
    ! Tie:  vedi JumpOver.
    Touch: switch(n) {
	1: "Tieni a posto le mani!";
	2: "Non succede niente di particolare.";
	3: "Se pensi che ci@`o sia utile.";
    }
    ! Turn: vedi Pull.
    Unlock: switch(n) {
	1: "Cerca un'altra soluzione.";
	2: " Non ", (isorare) x1, " chius", (genderandnumber) x1, 
	     " a chiave in questo momento.";
	3: if (x1 has pluralname) print "Non sembrano ";
	   else print "Non sembra ";
	   "entrare nella serratura.";
	4: "Ora hai aperto ", (the) x1, ".";
    }
    VagueGo: "Dovresti indicare l'esatta direzione in cui vuoi 
              andare.";
    Verify: switch(n) {
	1: "Il file di gioco @`e intatto.";
	2: "Il file di gioco non @`e stato verificato come intatto, e
	    potrebbe essere danneggiato.";
    }
    Wait: "Il tempo passa.";
    Wake: "Questo non @`e un sogno. @`E la spaventosa verit@`a.";
    WakeOther: "Non sembra necessario.";
    Wave: switch(n) {
	1: "Ma non ", (itorthem) x1, " possiedi.";
	2: "Sembri ridicolo, agitando ", (the) x1, ".";
    }
    WaveHands: "Ti agiti, sentendoti stupido.";
    Wear: switch(n) {
	1: "Non ", (itorthem) x1, " puoi indossare!";
	2: "Non ", (itorthem) x1, " possiedi!";
	3: print_ret (citorthem) x1, " stai gi@`a indossando!";
	4: "Hai indossato ", (the) x1, ".";
    }
    ! Yes:  vedi No.

];
