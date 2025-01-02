/*
    Formes part de l’equip de desenvolupament d’un dels jocs de moda: el
    Paraulògic. Aquest joc consisteix en formar paraules a partir d’un conjunt de
    lletres (que cada dia canvien). Les paraules que es formen a cada jugada, han
    de contenir sempre la lletra “del mig” i han de ser vàlides. Es poden repetir
    lletres.
    Una paraula correcta de 3 lletres val 1 punt, una de 4 lletres val 2 punts, una de 5 o més val tants
    punts com lletres tingui la paraula i si té menys de 3 lletres val 0 punts.
    El conjunt de lletres el deses en una taula de 7 posicions, on la lletra de la primera posició és la lletra
    “del mig” que totes les paraules han de contenir. En el cas de l’exemple:
    cjt_lletres[0] = ‘G’;  La lletra del mig
    cjt_lletres[1] = ‘E’;
    cjt_lletres[2] = ‘N’;
    cjt_lletres[3] = ‘L’;
    cjt_lletres[4] = ‘O’;
    cjt_lletres[5] = ‘A’;
    cjt_lletres[6] = ‘T’;
    En aquesta prova hauràs de dissenyar i escriure el codi de diferents components d’aquest joc.

    Exercici 1 (2 punts). Escriu, en llenguatge C, el procediment del_mig( ). Aquest procediment ha de
    retornar cert o fals en funció de si la paraula de la jugada (que es pasa al primer paràmetre) conté o
    no la lletra del mig, i té la capçalera següent:
    bool del_mig(char paraula[], char cjt_lletres[])
    La paraula de la jugada s’haurà introduït amb un scanf( ) i, per tant, acabarà amb el sentinella habitual
    per a les cadenes de caràcters.

    Exercici 2 (3 punts). Escriu, en llenguatge C, el procediment punts_paraula( ). Aquest procediment
    ha de retornar el número de punts que val una paraula, en funció del que hem descrit anteriorment:
    int punts_paraula(char paraula[], char cjt_lletres[])
    Per tant, ha de comprovar que la lletra del mig es fa servir i que la paraula és vàlida. Si la paraula no
    conté la lletra del mig o no és vàlida, retorna -1. Per fer això darrer, utilitzaràs un procediment que
    indica si una paraula es troba o no al diccionari:
    bool diccionari(char paraula[])

    Exercici 3 (3 punts). Escriu en pseudocodi un programa principal que permeti jugar al Paraulògic. Et
    mostrem una possible sortida per pantalla del joc i tu només has d’escriure el programa.
    Benvingut/da al PARAULÒGIC
    E N
    T [G] L
    A O
    Punts totals: 0
    Vols introduir una paraula? (1 = sí, 0 = no) 1
    Quina paraula proposes? gol
    La paraula és vàlida i val 1 punt.
    Punts totals: 1
    Vols introduir una paraula? (1 = sí, 0 = no) 1
    Quina paraula proposes? golet
    La paraula no és vàlida.
    Punts totals: 1
    Vols introduir una paraula? (1 = sí, 0 = no) 0
    Fins la propera!
    Disposes dels següents procediments que has d’utilitzar:
    • inicia_joc( ) Per iniciar el joc i escollir el conjunt de lletres
    $ **
    $ Procediment que escull el conjunt de lletres pel joc
    $ @param cjt_lletres (Ref (S): taula[7] de caràcters) La posició $ 0 indica
    la lletra del mig.
    $ **
    inicia_joc(var cjt_lletres: taula[7] de caràcters)
    • mostra_cjt( ) per mostrar el conjunt de lletres per pantalla
    $ **
    $ Procediment mostra el conjunt de lletres pel joc
    $ @param cjt_lletres (Valor (E): taula[7] de caràcters)
    $ **
    mostra_cjt(cjt_lletres: taula[7] de caràcters)
    • neta_i_majúscules( ) Fixa’t que l’usuari pot introduir la paraula amb minúscules o amb
    majúscules, pot posar accents.... Abans de tractar la paraula, cal usar aquest procediment
    que converteix la paraula a majúscules, per si de cas l’usuari ho ha fet en minúscules. A més,
    neteja la paraula d’accents i dièresis, per facilitar la comparació entre les lletres d’una paraula
    i les lletres escollides per la partida. Per exemple, amb aquest procediment la paraula “aigües”
    es transformaria a “AIGUES”.
    $ **
    $ Neteja d’accents i dièresis i passa a majúscules
    $ @param paraula (Ref (E/S): taula[MAX] de caràcters, amb el
    $ sentinella habitual)
    $ **
    neta_i_majúscules (var paraula: taula[MAX] de caràcters)
    Per simplificar el disseny i tenint en compte que és un exercici d’examen, suposem que mai es
    tornarà a introduir una paraula que ja s’ha introduït abans (altrament, s’anirien sumant punts).

    Exercici 4 (2 punts)
    Les puntuacions de cada partida es van guardant en un servidor. Altres persones han treballat en el
    programa i han decidit que cada puntuació es desa en un registre definit com a tipus:
    tipus
    puntuació_t: registre
    n_partida: enter; $ Identificador de partida
    n_punts: enter; $ Punts fets en la partida
    n_paraules: enter; $ Paraules encertades en la partida
    fregistre
    ftipus
    Han programat un codi amb el qual s’aconsegueix que un servidor tingui les puntuacions de les
    partides desades en una taula de puntuacions. Completa en pseudocodi el següent procediment:
    $ **
    $ El procediment indica l’identificador de partida que conté el màxim de punts.
    $ @param punt (Valor (E): taula[MAX] de puntuació_t). Taula de puntuacions.
    $ @param n_p (Valor (E): enter). Nombre de partides.
    $ @return Identificador de la partida amb més punts
    $ **
    funció millor_partida(punt: taula[MAX] de puntuació_t; n_p: enter) retorna enter
    Nota: Si hi ha vàries partides amb el mateix número de puntuacions, es pot proporcionar tant la
    primera com l’última amb aquesta puntuació.
 */