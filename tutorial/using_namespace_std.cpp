// "using" stosuje się tylko do scope'a w którym zostało użyte
// nigdy nie powinno się robić "using namespace" w plikach .h
// nieużywanie "using namespace" zwiększa troche czytelność kodu ponieważ dzięki temu wiemy dokładnie z czego korzystamy
// jeśli już musimy użyć "using namespace" to najlepiej robić to tylko w jakichś scope'ach (typu if statementy, funkcje)
// używanie "using namespace" w pliku .cpp jest still lepsze niż używanie tego w pliku .h