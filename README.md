# Ondrej-Polanecky

- task01: 1

## task01
Proměnnou result by bylo vhodné zapsat jako statickou proměnnou uvnitř `toUpper()`, aby ji jiný kód nemohl měnit. Také by bylo vhodné nějak ošetřit situaci, kdy by její vstup měl být delší než 63 znaků-

## task02
Zatím nic

## task03
Výborně. Pouze u funkce `fscanf` dejte pozor u `"%s"` parametru na přetečení délky vstupu. Jednou z možností je použít `"%254[^\1]"`, která přečte max. 254 znaků (přidá se ještě ukončovací \0) až do konce souboru nebo výskytu \1 (který se v textu prakticky nevyskytuje, nemůžeme použít \0, neboť tento znak ukončuje řetězec). Při čtení binárního souboru, kde se mohou vyskytnout znaky \0 i \1 lze použít `fread`.

## task04
V pořádku.

## task06
Doplnil jsem vysvětlení, ale nejsem si úplně jist správností.

## task07
Výborně.