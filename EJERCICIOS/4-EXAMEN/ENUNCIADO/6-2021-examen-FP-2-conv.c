/*
    Exercici 1 (2 punts)

        Una de les primeres coses que et demanen és fer un procediment en C que indiqui quants
        encerts té una aposta. L’aposta es guarda en una taula de 6 enters, mentre que la
        combinació guanyadora es guarda en una altra taula de 6 enters. Nota: els enters de les
        dues taules no tenen perquè estar ordenats. La capçalera és la següent:

    int encerts(int aposta[], int combinacio_guanyadora[])

    Exercici 2 (2 punts)

        Després de discutir-te amb la teva cap, arribeu a la conclusió que el millor és que els enters
        de la combinació guanyadora estiguin ordenats. Per exemple, si en el cas anterior la
        combinació guanyadora era {7, 1, 23, 12, 33, 9} ara el paràmetre seria {1, 7, 9, 12, 23, 33}.
        Escriu de nou el procediment anterior de manera que sigui més eficient, tenint en compte
        que ara la combinació guanyadora tindrà els números ordenats.

    Exercici 3 (3 punts)

        Ara et demanen de fer un procediment en C, anomenat mes_repetit( ), que indiqui com a
        retorn quin és el número més repetit del darrer any.
        Per si no ho saps, els nombres que poden sortir a la loteria son des de 1 fins al 49. Tenint
        en compte que cada any es fan 104 sortejos, la informació d’aquestes combinacions es
        passarà al procediment en una taula de 104 files i 6 columnes.
        En aquesta ocasió, no només has d’escriure el codi del procediment, sinó també la seva
        capçalera.

    Exercici 4 (3 punts)

        Et demanem que escriguis, en pseudocodi, un programa que:
        1. Demani per teclat a l’usuari els 6 números que ha jugat a la 6/49.
        2. Utilitzi un procediment anomenat obté_guanyadora( ) per carregar la combinació
        guanyadora en una taula d’enters. Aquest procediment NO l’has de descriure.
        3. Indiqui per pantalla el nombre d’encerts. Addicionalment, si hi ha menys de tres
        encerts ha de dir “Ho sentim! La teva aposta no ha obtingut cap premi”. Si hi ha tres
        encerts o més ha de dir “Enhorabona! La teva aposta ha tingut premi”.
        Aquesta és la capçalera del procediment que has d’utilitzar:

        $ **
        $ El procediment es connecta a un servidor i carrega les dades de la combinació guanyadora
        $ @param combinacio (ref. (S): taula[MAX] d’enters). La combinació guanyadora.
        $ **

        acció obté_guanyadora(var combinacio: taula[6] d’enters)
        Recorda que també has d’utilitzar el procediment que has escrit a l’exercici 1 o 2.


*/