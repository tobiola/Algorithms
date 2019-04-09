package main

import (
  "fmt"
)

func main() {
  sentence := "peter piper picked a peck of pickled peppers";
  word := "pickle";
  total := 0;

  for i := 0; i < len(sentence)- len(word); i++ {
    compStr := sentence[i:i + len(word)]
    comp := 0
    for j := 0; j < len(word); j++ {
      comp++
      if word[j] != compStr[j] {
        break
      }
    }
    fmt.Printf("substr: %v\tcmp: %v\n", compStr, comp);
    total += comp
    if (comp == len(word)) {
      break
    }
  }
  fmt.Println("Total comparisons: %v\n", total);
}
