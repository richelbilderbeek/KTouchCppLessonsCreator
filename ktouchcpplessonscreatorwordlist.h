#ifndef KTOUCHCPPLESSONSCREATORWORDLIST_H
#define KTOUCHCPPLESSONSCREATORWORDLIST_H

#include <random>
#include <string>
#include <vector>

namespace ribi {
namespace ktclc {

///All words used
struct word_list
{
  ///Create a word list that
  /// - contains the characters taught in the lesson
  /// - has a preference for the new characters
  word_list(
    const std::string& chars_in_lesson,
    const std::string& new_characters,
    std::mt19937& rng_engine
  ) noexcept;

  ///Get all the words that can currently be handled ky KTouch
  const std::vector<std::string>& get_all_legal_and_fitting() const noexcept { return m_all_legal_and_fitting; }

  ///Get all the words that can currently be handled ky KTouch and are new in this lesson
  const std::vector<std::string>& get_all_legal_and_fitting_and_new() const noexcept { return m_all_legal_and_fitting_and_new; }

  const std::vector<std::string>& get_new_char_words() const noexcept { return m_new_char_words; }

  const std::string& get_chars_in_lesson() const noexcept { return m_chars_in_lesson; }

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  private:
  //const std::vector<std::string> m_all;
  //const std::vector<std::string> m_all_legal;
  const std::vector<std::string> m_all_legal_and_fitting;
  const std::vector<std::string> m_all_legal_and_fitting_and_new;
  const std::string m_chars_in_lesson;
  const std::vector<std::string> m_new_char_words;

  ///Create all the words I want to train
  static std::vector<std::string> create_all() noexcept;

  ///Create all the words that can currently be handled ky KTouch
  static std::vector<std::string> create_all_legal() noexcept;

  ///Create all the words that can currently be handled ky KTouch
  ///and contain the characters in this lesson
  static std::vector<std::string> create_all_legal_and_fitting(
    const std::string& chars_in_lesson
  ) noexcept;

  ///Create all the words that can currently be handled ky KTouch
  ///and contain the characters in this lesson
  ///and contain the new characters
  static std::vector<std::string> create_all_legal_and_fitting_and_new(
    const std::string& chars_in_lesson,
    const std::string& new_characters
  ) noexcept;

  static std::vector<std::string> create_new_char_words(
    const std::string& new_characters,
    const int how_many,
    const int level,
    std::mt19937& rng_engine
  ) noexcept;
};

///Determine the lesson index from the word list
///Simple the number of keys, divided by two
int get_lesson_index(const word_list& a_word_list) noexcept;
int get_lesson_index(const std::string& chars_in_lesson) noexcept;

} //~namespace ktclc
} //~namespace ribi


#endif // KTOUCHCPPLESSONSCREATORWORDLIST_H
