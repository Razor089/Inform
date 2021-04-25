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


! ItalianG.h (File per la grammatica italiana).
! Numero di Serie: 041014

System_file; 


! --------------------------------------------------------------------- 
!  I "meta-verbs", comandi per il gioco piuttosto che dentro il
!  gioco. Alcuni sono lasciati in inglese per maggior coerenza con
!  l'interprete che è in inglese.
! ---------------------------------------------------------------------


Verb meta 'fullscore' 'full' 'punti'
	*						-> FullScore
	* 'score'					-> FullScore;

Verb meta 'modalit@`a' 'modalita'
	* 'breve'/'corta'				-> LMode3
	* 'normale'					-> LMode1
	* 'lunga'/'completa'				-> LMode2;

Verb meta 'superbrief' 'short' 'breve'
	*						-> LMode3;

Verb meta 'verbose' 'long' 'lungo'
	*						-> LMode2;

Verb meta 'brief' 'normal' 'normale'
	*						-> LMode1;

Verb meta 'notify' 'notifica'
	* 'on'/'attivata'				-> NotifyOn
	* 'off'/'disattivata'				-> NotifyOff;

Verb meta 'pronouns' 'nouns' 'pronomi'
	*						-> Pronouns;

Verb meta 'q//' 'quit' 'die' 'uscire' 'fine' 'basta'
	*						-> Quit;

Verb meta 'restart' 'ricomincia' 'ricominciare'
	* 'partita'/'gioco'				-> Restart
	*						-> Restart;

Verb meta 'restore' 'carica' 'caricare' 'ricarica' 'riprendi' 'load'
	* 'partita'/'gioco'				-> Restore
	*						-> Restore;

Verb meta 'save' 'salva' 'salvare'
	* 'partita'/'gioco'				-> Save
	*						-> Save;

Verb meta 'score' 'punteggio'
	*						-> Score
	*'completo'/'pieno'				-> FullScore;

Verb meta 'script' 'transcript' 'trascrizione'
	*						-> ScriptOn
	* 'off'/'disattivata'				-> ScriptOff
	* 'on'/'attivata'				-> ScriptOn;

Verb meta 'noscript' 'unscript'
	*						-> ScriptOff;

Verb meta 'verify' 'verifica' 'verificare'
	* 'gioco'					-> Verify
	*						-> Verify;

Verb meta 'version' 'versione'
	*						-> Version;

Verb meta 'recording' 'registra' 'registrazione'
	*						-> CommandsOn
	* 'on'/'attivata'				-> CommandsOn
	* 'off'/'disattivata'				-> CommandsOff;

Verb meta 'replay'
	*						-> CommandsRead;

#Ifndef NO_PLACES;
Verb meta 'places' 'luoghi' 'posti'
	*						-> Places;

Verb meta 'objects' 'oggetti'
	*						-> Objects;

#Endif; ! NO_PLACES




! ---------------------------------------------------------------------
!  Verbi utilizzati nel debug.  
!  Sono stati lasciati in inglese, poichè usati solo dai game
!  designers.
! ---------------------------------------------------------------------

#ifdef DEBUG;

Verb meta 'actions'
	*						-> ActionsOn
	* 'on'						-> ActionsOn
	* 'off'						-> ActionsOff;

Verb meta 'changes'
	*						-> ChangesOn
	* 'on'						-> ChangesOn
	* 'off'						-> ChangesOff;

Verb meta 'gonear'
	* noun						-> Gonear;

Verb meta 'goto'
	* number					-> Goto;

Verb meta 'random'
	*						-> Predictable;

Verb meta 'routines' 'messages'
	*						-> RoutinesOn
	* 'on'						-> RoutinesOn
	* 'off'						-> RoutinesOff;

Verb meta 'scope'
	*						-> Scope
	* noun						-> Scope;

Verb meta 'showobj'
	*						-> Showobj
	* multi						-> Showobj;

Verb meta 'showverb'
	* special					-> Showverb;


Verb meta 'timers' 'daemons'
	*						-> TimersOn
	* 'on'						-> TimersOn
	* 'off'						-> TimersOff;

Verb meta 'trace'
	*						-> TraceOn
	* number					-> TraceLevel
	* 'on'						-> TraceOn
	* 'off'						-> TraceOff;

Verb meta 'abstract'
	* noun 'to' noun				-> XAbstract;

Verb meta 'purloin'
	* multi						-> XPurloin;

Verb meta 'tree'
	*						-> XTree
	* noun						-> XTree;

#Ifdef TARGET_GLULX;
Verb meta 'glklist'
	*						-> Glklist;

#Endif; ! TARGET_GLULX;


#Endif;

! --------------------------------------------------------------------
!  Ecco finalmente i verbi per il gioco
! --------------------------------------------------------------------

[ ADirection; if (noun in compass) rtrue; rfalse; ];


Verb 'rispondi' 'd@`i' 'di' 'di^' 'dici'
	* topic 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	  'agli'/'ai'/'alle' creature			-> Answer;

Verb 'chiedi' 'domanda'
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle' creature 'circa'/'su'/'sul'/
	  'sui'/'sullo'/'sull^'/'sulla'/'sugli'/
	  'sulle'/'di'/'dello'/'della'/'dell^'/'dei'/
	  'degli'/'delle' topic				-> Ask
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle' creature				-> Ask
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle' creature noun			-> AskFor
	* noun 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	  'agli'/'ai'/'alle' creature			-> AskFor reverse
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle' creature 'di' topic		-> AskTo
	* 'scusa'/'scuse'				-> Sorry
	* 'scusa'/'scuse' 'a'/'ad'/'all^'/'allo'/
	  'alla'/'al'/'agli'/'ai'/'alle' creature	-> Sorry;

Verb 'rompi' 'colpisci' 'combatti' 'uccidi'
     'tortura' 'lotta' 'sfonda' 'ammazza' 
     'picchia'
	* noun						-> Attack
	* noun 'con'/'col' held				-> Attack;

Verb 'attacca'
	* noun						-> Attack
	* noun 'con'/'col' held				-> Attack
	* noun 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	       'agli'/'ai'/'alle' noun			-> Tie;

Verb 'soffia'
	* 'dentro'/'in'/'nel'/'nello'/'nell^'/
	  'nella'/'negli'/'nelle'/'nei' held		-> Blow
	* held						-> Blow;

Verb 'impreca' 'bestemmia' 'maledici'
	*						-> Mild
	* topic						-> Mild;

Verb 'brucia' 'incendia'
	* noun						-> Burn
	* noun 'con'/'col' held				-> Burn;

Verb 'compra' 'acquista'
	* noun						-> Buy;

Verb 'scala' 'sali' 'arrampica' 'arrampicati'
	* 'su'/'sul'/'sullo'/'sull^'/'sulla'/'sui'/
	  'sugli'/'sulle'/'a'/'per' noun		-> Climb
	* noun						-> Climb;

Verb 'chiudi' 'copri'
	* noun						-> Close
	* noun 'con'/'col'/'a' held			-> Lock;

Verb 'consulta' 
	* noun 'circa' topic				-> Consult
	* noun 'su'/'sul'/'sullo'/'sull^'/'sulla'/
	  'sui'/'sugli'/'sulle'/'sopra' topic		-> Consult;

Verb 'taglia' 'affetta' 'sfronda' 'sfoltisci'
     'spacca' 'strappa'
	* noun						-> Cut
	* noun 'con'/'col' held				-> Cut;

Verb 'scava'
	* noun						-> Dig
	* noun 'con'/'col' held				-> Dig;

Verb 'bevi' 'trangugia' 'sorseggia'
	* noun						-> Drink;

Verb 'lascia' 'lancia' 'abbandona' 'posa'
	* multiheld					-> Drop
	* multiexcept 'dentro'/'in'/'nel'/'nello'/
	  'nell^'/'nella'/'negli'/'nelle'/
	  'nei' noun					-> Insert
	* multiexcept 'su'/'sul'/'sullo'/'sull^'/
	  'sulla'/'sui'/'sugli'/'sulle'/
	  'sopra' noun					-> PutOn
	* held 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	  'agli'/'ai'/'alle'/'su'/'sul'/'sullo'/
	  'sull^'/'sulla'/'sui'/'sugli'/'sulle'/
	  'sopra'/'contro'/'dentro'/'in'/'nel'/
	  'nello'/'nell^'/'nella'/'negli'/'nelle'/
	  'nei' noun					-> ThrowAt
	* noun=ADirection				-> Go
	* noun						-> Exit;

Verb 'mangia'
	* held						-> Eat;

Verb 'svuota' 'versa' 'rovescia'
	* noun						-> Empty
	* noun 'su'/'sul'/'sullo'/'sull^'/'sulla'/
	  'sui'/'sugli'/'sulle'/'sopra' noun		-> EmptyT;

Verb 'entra' 'attraversa' 'visita'
	*						-> GoIn
	* 'dentro'					-> GoIn
	* 'dentro'/'in'/'nel'/'nello'/'nell^'/
	  'nella'/'negli'/'nelle'/'nei' noun		-> Enter
	* 'dentro' 'a'/'ad'/'all^'/'allo'/'alla'/
	  'al'/'agli'/'ai'/'alle' noun			-> Enter
	* noun						-> Enter;

Verb 'esamina' 'x//' 'descrivi'
	* noun						-> Examine
	* 'con' 'attenzione'/'attentamente' noun	-> Search
	* noun 'con' 'attenzione'/'attentamente'	-> Search;

Verb 'fuori' 'esci'
	*						-> Exit
	* 'da'/'dal'/'dallo'/'dalla'/'dall^'/
	  'dai'/'dagli'/'dalle'/'di' noun		-> Exit;

Verb 'riempi' 'colma'
	* noun						-> Fill;

Verb 'dai' 'paga' 'offri' 'da'
	* held 'a'/'ad'/'all^'/'allo'/'alla'/
	  'al'/'agli'/'ai'/'alle' creature		-> Give
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	  'agli'/'ai'/'alle' creature held		-> Give reverse;


Verb 'vai' 'cammina' 'corri' 'va'
	*						-> VagueGo
	* 'fuori'/'via'					-> Exit
	* 'a'/'ad'/'verso' noun=ADirection		-> Go
	* noun						-> Enter
	* 'dentro'					-> GoIn
	* 'in'/'nel'/'nello'/'nell^'/'nella'/'nei'/
	  'negli'/'nelle'/'dentro'/'attraverso'/
	  'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle' noun				-> Enter
	* 'su'/'sul'/'sullo'/'sull^'/'sulla'/'sui'/
	  'sugli'/'sulle'/'sopra' noun			-> Climb;

Verb 'in' 'dentro'
	*						-> GoIn;

Verb 'inserisci'
	* multiexcept 'dentro'/'in'/'nel'/'nello'/
	  'nell^'/'nella'/'negli'/'nelle'/
	  'nei' noun					-> Insert;

Verb 'inventario' 'inv' 'i//'
	*						-> Inv
	* 'esteso'					-> InvTall
	* 'completo'					-> InvWide;

Verb 'salta'
	*						-> Jump
	* 'su'/'sul'/'sullo'/'sull^'/'sulla'/'sui'/
	  'sugli'/'sulle'/'sopra' noun			-> JumpOver;

Verb 'bacia' 'abbraccia'
	* creature					-> Kiss;

Verb 'senti' 'ascolta'
	*						-> Listen
	* noun						-> Listen;

Verb 'serra' 'blocca'
	* noun 'con'/'col' held				-> Lock;

Verb 'guarda' 'g//' 'vedi' 'l//'
	*						-> Look
	* noun						-> Examine
	* 'dentro'/'in'/'nel'/'nello'/'nell^'/'nella'/
	  'negli'/'nelle'/'nei'/'attraverso'/'su'/
	  'sul'/'sullo'/'sull^'/'sulla'/'sui'/'sugli'/
	  'sulle'/'sopra'/'tra'/'fra' noun		-> Search
    * 'con' 'attenzione'/'attentamente' noun		-> Search
	* noun 'con' 'attenzione'/'attentamente'	-> Search
	* 'sotto' noun					-> LookUnder
	* topic 'dentro'/'in'/'nel'/'nello'/'nell^'/
	  'nella'/'negli'/'nelle'/'nei' noun		-> Consult
	* noun=ADirection				-> Examine
	* 'a' noun=ADirection				-> Examine;

Verb 'no'
	*						-> No;

Verb 'apri' 'scopri'
	* noun						-> Open
	* noun 'con'/'col'/'a' held			-> Unlock;

Verb 'pela' 'sbuccia'
	* noun						-> Take;

Verb 'prega'
	*						-> Pray;

Verb 'tira' 'trascina'
	* noun						-> Pull;

Verb 'premi' 'muovi' 'spingi'
	* noun						-> Push
	* noun 'verso'/'a' noun=ADirection		-> PushDir
	* noun 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	  'agli'/'ai'/'alle' noun			-> PushDir;


! 21 Dic 2003: Tolto "METTITI" come sinonimo di METTI
! Vedi file INFIT.OSS per eventuali commenti.

Verb 'metti'
	* held						-> Wear
	* 'gi@`u'/'giu'/'giu^' multiheld		-> Drop
	* multiheld 'gi@`u'/'giu'			-> Drop
	* multiexcept 'dentro'/'in'/'nel'/'nello'/
	  'nell^'/'nella'/'negli'/'nelle'/
	  'nei' noun					-> Insert
	* multiexcept 'su'/'sul'/'sullo'/'sull^'/
	  'sulla'/'sui'/'sugli'/'sulle'/
	  'sopra' noun					-> PutOn;

Verb 'leggi'
	* noun						-> Examine
	* 'circa' topic 'dentro'/'in'/'nel'/'nello'/
	  'nell^'/'nella'/'negli'/'nelle'/
	  'nei' noun					-> Consult
	* topic 'dentro'/'in'/'nel'/'nello'/'nell^'/
	  'nella'/'negli'/'nelle'/'nei' noun		-> Consult;

Verb 'rimuovi' 'togli'
	* held						-> Disrobe
	* worn						-> Disrobe
	* multi						-> Take
	* multiinside 'da'/'dal'/'dallo'/'dalla'/
	  'dall^'/'dagli'/'dalle'/'dai' noun		-> Remove;

Verb 'pulisci' 'strofina' 'spolvera' 'ripulisci' 
     'lucida' 'lustra'
	* noun						-> Rub;

Verb 'cerca' 'trova' 'ricerca' 'fruga'
!	* noun						-> Search
	* 'dentro'/'in'/'nel'/'nello'/'nell^'/'nella'/
	  'negli'/'nelle'/'nei'/'fra'/'tra' noun	-> Search
	* topic 'dentro'/'in'/'nel'/'nello'/'nell^'/
	  'nella'/'negli'/'nelle'/'nei'/'fra'/
	  'tra' noun					-> Consult reverse
	* 'dentro'/'in'/'nel'/'nello'/'nell^'/'nella'/
	  'negli'/'nelle'/'nei'/'fra'/
	  'tra' noun topic				-> Consult;

Verb 'imposta'
	* noun						-> Set
	* noun 'a'/'su' special				-> SetTo;

Verb 'mostra' 'presenta'
	* held 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	  'agli'/'ai'/'alle' creature			-> Show
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle' creature held			-> Show reverse;

Verb 'merda' 'cazzo' 'dannazione' 'porco'
	*						-> Strong;

Verb 'canta'
	*						-> Sing;

Verb 'siedi' 'siediti' 'sdraiati'
	* 'su'/'sul'/'sullo'/'sull^'/'sulla'/'sui'/
	  'sugli'/'sulle'/'sopra' noun			-> Enter
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle' noun				-> Enter
	* 'dentro'/'in'/'nel'/'nello'/'nell^'/
	  'nella'/'negli'/'nelle'/'nei' noun		-> Enter;

Verb 'dormi' 'sonnecchia'
	*						-> Sleep;

Verb 'annusa' 'odora'
	*						-> Smell
	* noun						-> Smell;

Verb 'spiacente' 'scusa'
	*						-> Sorry;

Verb 'schiaccia' 'spremi' 'spiaccica'
	* noun						-> Squeeze;

Verb 'stai' 'sta'
	* 'su'/'sul'/'sullo'/'sull^'/'sulla'/'sui'/
	  'sugli'/'sulle'/'sopra' noun			-> Enter
	* 'dentro'/'in'/'nel'/'nello'/'nell^'/
	  'nella'/'negli'/'nelle'/'nei' noun		-> Enter;

Verb 'nuota'
	*						-> Swim;

Verb 'scuoti'
	* noun						-> Swing;

Verb 'attiva' 'accendi'
	* noun						-> Switchon;

Verb 'disattiva' 'spegni'
	* noun						-> Switchoff;

Verb 'prendi' 'trasporta' 'afferra' 'raccogli'
	* multi						-> Take
	* multiinside 'da'/'dal'/'dallo'/'dalla'/
	  'dall^'/'dagli'/'dalle'/'dai' noun		-> Remove;

Verb 'assaggia' 'assapora' 'gusta'
	* noun						-> Taste;

Verb 'parla'
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle'/'con'/'col' creature 'circa'/'su'/
	  'sul'/'sullo'/'sull^'/'sulla'/'sugli'/'sui'/
	  'sulle'/'di'/'dello'/'della'/'dell^'/'dei'/
	  'degli'/'delle' topic				-> Tell
	* 'a'/'ad'/'all^'/'allo'/'alla'/'al'/'agli'/
	  'ai'/'alle'/'con'/'col' creature		-> Tell;

Verb 'pensa' 'medita' 'rifletti'
	*						-> Think;

Verb 'lega' 'fissa' 'congiungi' 'unisci' 
     'allaccia' 'annoda'
	* noun						-> Tie
	* noun 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	  'agli'/'ai'/'alle' noun			-> Tie
	* noun 'con'/'col' noun				-> Tie;

Verb 'tocca' 'accarezza' 'palpa'
	* noun						-> Touch;

Verb 'trasferisci' 'sposta'
	* noun						-> Push
	* noun 'su'/'sul'/'sullo'/'sull^'/'sulla'/
	  'sui'/'sugli'/'sulle'/'sopra' noun		-> Transfer
	* noun 'dentro'/'in'/'nel'/'nello'/'nell^'/
	  'nella'/'negli'/'nelle'/'nei' noun		-> Transfer;

Verb 'gira' 'ruota'
	* noun						-> Turn
	* noun 'a on'/'su on'				-> Switchon
	* noun 'a off'/'su off'				-> Switchoff;

Verb 'agita' 'agitati'
	* noun						-> Wave;

Verb 'saluta'
!	*						-> WaveHands
	* creature					-> WaveHands;

Verb 'indossa'
	* held						-> Wear;

Verb 'si' 's@`i'
	*						-> Yes;

Verb 'scassina' 'sblocca'
	* noun 'con'/'col'/'a' held			-> Unlock;

Verb 'aspetta' 'attendi' 'z//'
	*						-> Wait;

Verb 'sveglia' 'svegliati' 'risveglia' 'risvegliati'
	*						-> Wake
	* creature					-> WakeOther;

Verb 'scendi'
	*						-> Exit
	* 'da'/'dal'/'dallo'/'dalla'/'dall^'/
	  'dai'/'dagli'/'dalle' noun			-> Exit
	* noun						-> Exit;

Verb 'fai' 'fa'
	*						-> GenericVerb
	* 'inventario'					-> Inv
	* 'vedere' held 'a'/'ad'/'all^'/'allo'/'alla'/
	  'al'/'agli'/'ai'/'alle' creature		-> Show
	* 'vedere' 'a'/'ad'/'all^'/'allo'/'alla'/'al'/
	  'agli'/'ai'/'alle' creature held		-> Show reverse
	* held 'vedere' 'a'/'ad'/'all^'/'allo'/
	  'alla'/'al'/'agli'/'ai'/'alle' creature	-> Show;






!   Il codice che segue è identico a quello in Grammar.h (il file per
!   la grammatica inglese), ed è lasciato così com'è perché definisce
!   alcune funzioni standard di libreria


! ------------------------------------------------------------------------------
!  This routine is no longer used here, but provided to help existing games
!  which use it as a general parsing routine:

[ ConTopic w;
    consult_from = wn;
    do w = NextWordStopped();
    until (w == -1 || (w == 'to' && action_to_be == ##Answer));
    wn--;
    consult_words = wn-consult_from;
    if (consult_words == 0) return -1;
    if (action_to_be == ##Answer or ##Ask or ##Tell) {
        w = wn; wn = consult_from; parsed_number = NextWord();
        if (parsed_number == 'the' && consult_words > 1) parsed_number = NextWord();
        wn = w;
        return 1;
    }
    return 0;
];

! ------------------------------------------------------------------------------
!  Final task: provide trivial routines if the user hasn't already:
! ------------------------------------------------------------------------------

#Stub AfterLife         0;
#Stub AfterPrompt       0;
#Stub Amusing           0;
#Stub BeforeParsing     0;
#Stub ChooseObjects     2;
#Stub DarkToDark        0;
#Stub DeathMessage      0;
#Stub GamePostRoutine   0;
#Stub GamePreRoutine    0;
#Stub InScope           1;
#Stub LookRoutine       0;
#Stub NewRoom           0;
#Stub ParseNumber       2;
#Stub ParserError       1;
#Stub PrintTaskName     1;
#Stub PrintVerb         1;
#Stub TimePasses        0;
#Stub UnknownVerb       1;

#Ifdef TARGET_GLULX;
#Stub HandleGlkEvent    2;
#Stub IdentifyGlkObject 4;
#Stub InitGlkWindow     1;
#Endif; ! TARGET_GLULX

#Ifndef PrintRank;
Constant Make__PR;
#Endif;

#Ifdef Make__PR;
[ PrintRank; "."; ];
#Endif;

#Ifndef ParseNoun;
Constant Make__PN;
#Endif;

#Ifdef Make__PN;
[ ParseNoun obj; obj = obj; return -1; ];
#Endif;

#Default Story 0;
#Default Headline 0;

#Ifdef INFIX;
#Include "infix";
#Endif;

Constant LIBRARY_GRAMMAR;       ! for dependency checking
