// Tak jak chápu dependency inversion principle, tak jde o vhodně použitou abstrakci. 
// Moduli na vysoké úrovni by neměli záviset na modulech na nízké úrovni. Měli by se snadno znovupoužívat a neměli by se rozbít pokud se udělá
// nějaká změna na nízké úrovni. A naopak moduly na nízké úrovni by neměli záviset na modulech na vysoké úrovni. Toho dosáhneme díky abstrakci.
// Díky této abstrakci rozdělíme moduli na vysoké úrovni od modulů na nízké úrovni. Například metoda rozsviť_světla() na vysoké úrovni má za
// úkol rozsvítit světla, nemělo by záležet jakým způsobem se světla rozsvítí. I když se způsob rozsvícení světel úplně zmení tak by měla
// tato metoda pořád fungovat správně. Popravdě si nejsem úplně jistý jestli chápu dependency inversion principle správně. Je tento příklad
// správně?
