#include "cue_testfixture"
class CueTimingsGeneralStructure : public CueTest { };

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by mix of U+0009
 CHARACTER TABULATION characters and U+0020 SPACE characters
 characters

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.
 */

TEST_F(CueTimingsGeneralStructure, CueTimingsSeperator1LeftMix)
{
  loadVtt( "cue-times/separator/cuetimings_separator_1_space_left_mix.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
}

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by mix of U+0009
 CHARACTER TABULATION characters and U+0020 SPACE characters
 characters

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.
 */
TEST_F(CueTimingsGeneralStructure, CueTimingsSeperator1RightMix)
{
  loadVtt( "cue-times/separator/cuetimings_separator_1_space_right_mix.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
}

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by multiple U+0020 SPACE
 characters

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.
 */
TEST_F(CueTimingsGeneralStructure, CueTimingsSeperatorNSpace)
{
  loadVtt( "cue-times/separator/cuetimings_separator_n_space_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
}

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by multiple U+0009
 CHARACTER TABULATION characters
 characters

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.
 */
TEST_F(CueTimingsGeneralStructure, CueTimingsSeperatorNTab)
{
  loadVtt( "cue-times/separator/cuetimings_separator_n_tab.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
}

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by mix of U+0009
 CHARACTER TABULATION characters and U+0020 SPACE characters
 characters

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.
*/
TEST_F(CueTimingsGeneralStructure, CueTimingsSeperatorNLMix)
{
  loadVtt( "cue-times/separator/cuetimings_separator_n_spaces_left_mix.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
}

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by mix of U+0009
 CHARACTER TABULATION characters and U+0020 SPACE characters
 characters

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.
*/
TEST_F(CueTimingsGeneralStructure, CueTimingsSeperatorNRMix)
{
  loadVtt( "cue-times/separator/cuetimings_separator_n_spaces_right_mix.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
}

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by mix of U+0009
 CHARACTER TABULATION characters and U+0020 SPACE characters
 characters

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.
*/
TEST_F(CueTimingsGeneralStructure, CueTimingsSeperatorXMix)
{
  loadVtt( "cue-times/separator/cuetimings_separator_n_spaces_tabs_on_both_sides.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
}

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by
 no whitespace characters to the left. Parser does not require whitespace around separator.

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.

 From http://www.whatwg.org/specs/web-apps/current-work/#skip-whitespace (23/01/2013):
 From http://www.whatwg.org/specs/web-apps/current-work/#collect-a-sequence-of-characters (23/01/2013):
 3. While position doesn't point past the end of input and the character at position is one of the characters,
    append that character to the end of result and advance position to the next character in input.
*/
TEST_F(CueTimingsGeneralStructure, CueTimingsSeparatorMissingLeft)
{
  loadVtt( "cue-times/separator/cuetimings_separator_0_spaces_left.vtt", 1 );
  const Error &err = getError( 0 );
  /**
   * The cue is processed
   */
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
  /**
   * We're expecting a WEBVTT_EXPECTED_WHITESPACE error on the 13 column of the 3rd line
   */
  ASSERT_EQ( WEBVTT_EXPECTED_WHITESPACE, err.error() );
  ASSERT_EQ( 3, err.line() );
  ASSERT_EQ( 13, err.column() );
}

/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by
 no whitespace characters to the right. Parser does not require whitespace around separator.

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.

 From http://www.whatwg.org/specs/web-apps/current-work/#skip-whitespace (23/01/2013):
 From http://www.whatwg.org/specs/web-apps/current-work/#collect-a-sequence-of-characters (23/01/2013):
 3. While position doesn't point past the end of input and the character at position is one of the characters,
    append that character to the end of result and advance position to the next character in input.
*/
TEST_F(CueTimingsGeneralStructure, CueTimingsSeparatorMissingRight)
{
  loadVtt( "cue-times/separator/cuetimings_separator_0_spaces_right.vtt", 1 );
  const Error &err = getError( 0 );
  /**
   * The cue is processed
   */
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
  /**
   * We're expecting a WEBVTT_EXPECTED_WHITESPACE error on the 17 column of the 3rd line
   */
  ASSERT_EQ( WEBVTT_EXPECTED_WHITESPACE, err.error() );
  ASSERT_EQ( 3, err.line() );
  ASSERT_EQ( 17, err.column() );
}
  
/*
 Test expecting parser to succeed when a cue's timestamp separator surrounded by
 no whitespace characters. Parser does not require whitespace around separator.

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
    Otherwise, let cue's text track cue start time be the collected time.
 5. Skip whitespace.
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 9. Skip whitespace.
 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure.
     Otherwise, let cue's text track cue end time be the collected time.

 From http://www.whatwg.org/specs/web-apps/current-work/#skip-whitespace (23/01/2013):
 From http://www.whatwg.org/specs/web-apps/current-work/#collect-a-sequence-of-characters (23/01/2013):
 3. While position doesn't point past the end of input and the character at position is one of the characters,
    append that character to the end of result and advance position to the next character in input.
*/
TEST_F(CueTimingsGeneralStructure, CueTimingsSeperatorMissingBoth)
{
  loadVtt( "cue-times/separator/cuetimings_separator_0_spaces.vtt", 1 );
  const Error &err = getError( 0 );
  const Error &err2 = getError( 1 );
  /**
   * The cue is processed
   */
  ASSERT_EQ( getCue( 0 ).startTime().value(), 25000);
  ASSERT_EQ( getCue( 0 ).endTime().value(), 27000);
  /**
   * We're expecting a WEBVTT_EXPECTED_WHITESPACE error on the 13 column of the 3rd line
   */
  ASSERT_EQ( WEBVTT_EXPECTED_WHITESPACE, err.error() );
  ASSERT_EQ( 3, err.line() );
  ASSERT_EQ( 13, err.column() );
  /**
   * We're expecting a WEBVTT_EXPECTED_WHITESPACE error on the 16 column of the 3rd line
   */
  ASSERT_EQ( WEBVTT_EXPECTED_WHITESPACE, err2.error() );
  ASSERT_EQ( 3, err2.line() );
  ASSERT_EQ( 16, err2.column() );
}

/*
 Test expecting parser to succeed when the cue has the arrow malformed.
 The parser will discard bad cues.

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 
 From http://dev.w3.org/html5/webvtt/#webvtt-parser-algorithm (23/01/2013):
 37. Collect WebVTT cue timings and settings from line, using cue for the results.
     If that fails, jump to the step labeled bad cue.
 50. Bad cue: Discard cue.
*/
TEST_F(CueTimingsGeneralStructure, CueTimingsArrowMalformed)
{
  loadVtt( "cue-times/separator/cuetimings_arrow_bad.vtt", 0 );
  const Error &err = getError( 0 );
  /**
   * We're expecting a WEBVTT_EXPECTED_CUETIME_SEPARATOR error on the 14 column of the 3rd line
   */
  ASSERT_EQ( WEBVTT_EXPECTED_CUETIME_SEPARATOR, err.error() );
  ASSERT_EQ( 3, err.line() );
  ASSERT_EQ( 14, err.column() );
}

/*
 Test expecting parser to succeed when the cue has the arrow malformed.
 The parser will discard bad cues.

 From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (23/01/2013):
 6. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 7. If the character at position is not a U+002D HYPHEN-MINUS character (-)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>)
    then abort these steps and return failure. Otherwise, move position forwards one character.
 
 From http://dev.w3.org/html5/webvtt/#webvtt-parser-algorithm (23/01/2013):
 37. Collect WebVTT cue timings and settings from line, using cue for the results.
     If that fails, jump to the step labeled bad cue.
 50. Bad cue: Discard cue.
*/
TEST_F(CueTimingsGeneralStructure, CueTimingsArrowMissing)
{
  loadVtt( "cue-times/separator/cuetimings_arrow_missing.vtt", 0 );
  const Error &err = getError( 0 );
  /**
   * We're expecting a WEBVTT_MISSING_CUESETTING_DELIMITER error on the 15 column of the 3rd line
   */
  ASSERT_EQ( WEBVTT_MISSING_CUESETTING_DELIMITER, err.error() );
  ASSERT_EQ( 3, err.line() );
  ASSERT_EQ( 15, err.column() );
}
