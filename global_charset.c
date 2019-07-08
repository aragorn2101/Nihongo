/*
 *  Initialisation of global variables.
 *
 *  Source file contains the character sets we are using for the conversions.
 *
 */


/***  BEGIN Global variables  ***/

/*  Kanji character sets for numbers  */
/*  Ones  */
char *k_ones[10] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"} ;
/*                    0     1     2     3     4     5     6     7     8     9   */

/*  Factors of 10  */
/*                          0    1     2     3         */
char *k_factors[2][5] = { {"", "十", "百", "千", ""},
                          {"", "万", "億", "兆", "京"} };
/*                          0    1     2     3     4   */
/*  First row contains factors up to 10**3: 10**0 x 10**index
 *  Second row: 10**3 x 10**index
 *  Element with index 0 is left blank so that the powers of
 *  10 progress with the index; this makes it easier to implement
 *  the loop which translates the numbers.
 */


/*  Hiragana names for the numbers  */
/*  Ones  */
char *h_ones[10] = {  "れい",    // 0
                      "いち",    // 1
                        "に",    // 2
                      "さん",    // 3
                      "よん",    // 4
                        "ご",    // 5
                      "ろく",    // 6
                      "なな",    // 7
                      "はち",    // 8
                    "きゅう" };  // 9

/*  Factors of 10  */
/*  + exceptions   */
char *h_factors[23] = {        "じゅう",    //  0 : 10
                               "ひゃく",    //  1 : 100
                                 "せん",    //  2 : 1000
                                 "まん",    //  3 : 10,000
                                 "おく",    //  4 : 100,000,000
                               "ちょう",    //  5 : 1,000,000,000,000
                                 "けい",    //  6 : 10,000,000,000,000,000
                           "さんびゃく",    //  7 : 300
                           "ろっぴゃく",    //  8 : 600
                           "はっぴゃく",    //  9 : 800
                             "さんぜん",    // 10 : 3000
                             "はっせん",    // 11 : 8000
                           "いっちょう",    // 12 :    1,000,000,000,000
                           "はっちょう",    // 13 :    8,000,000,000,000
                         "じゅっちょう",    // 14 :   10,000,000,000,000
                         "ひゃくちょう",    // 15 :  100,000,000,000,000
                       "いっせんちょう",    // 16 : 1000,000,000,000,000
                             "いっけい",    // 18 : 10,000,000,000,000,000
                             "ろっけい",    // 19 : 60,000,000,000,000,000
                             "はっけい",    // 20 : 80,000,000,000,000,000
                           "じゅっけい",    // 21 : 100,000,000,000,000,000
                         "ひゃくっけい",    // 22 : 1000,000,000,000,000,000
                         "いっせんけい" };  // 23 : 10,000,000,000,000,000,000

/***  END Global variables  ***/
