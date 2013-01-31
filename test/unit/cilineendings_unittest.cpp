#include "cue_testfixture"
class CueIdLineEndings : public CueTest { };

/**
 * Test if parser fails if there are no line endings (LF OR CRLF) between WEBVTT signature and cue
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 11. Header: Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 13. The character indicated by position is a U+000A LINE FEED (LF) character. Advance position to the next character in input.
 * 14. If line contains the three-character substring "-->" (U+002D HYPHEN-MINUS, U+002D HYPHEN-MINUS, U+003E GREATER-THAN SIGN), then set the already collected line flag and jump to the step labeled cue loop
 * 15. If line is not the empty string, then jump back to the step labeled header.
 */
TEST_F(CueIdLineEndings, MissingBetweenSignatureAndId)
{
  loadVtt( "cue-ids/lineendings/missing_between_signature_and_Id.vtt", 1 );
  const Error &err = getError( 0 );
  /**
   * Parser doesn't care if there is a blank line between cues or not.
   */
  // Doesn't work, causes crash, test needed
  ASSERT_STREQ( (wchar_t *)getCue( 0 ).id().text(), L"" );
  /**
   * We're expecting a WEBVTT_EXPECTED_EOL error on the 1st column of the 2nd line
   */
  ASSERT_EQ( WEBVTT_EXPECTED_EOL, err.error() );
  ASSERT_EQ( 2, err.line() );
  ASSERT_EQ( 1, err.column() );
}

/**
 * Test if parser fails if there are two line ending characters (LF or CRLF) between cue id and cue timestamp
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 
 * 17. Collect a sequence of characters that are U+000A LINE FEED (LF) characters.
 * 18. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 31. Let cue's text track cue identifier be line.
 * 33. If the character indicated by position is a U+000A LINE FEED (LF) character, advance position to the next character in input.
 * 34. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 35. If line is the empty string, then discard cue and jump to the step labeled cue loop.
 */
TEST_F(CueIdLineEndings, TwoBetweenIdAndTimestamp)
{
  loadVtt( "cue-ids/lineendings/two_between_id_and_timestamp.vtt", 1 );
  const Error &err = getError( 0 );
  /**
   * Parser doesn't care if there is a blank line between cues or not.
   */
  // Doesn't work, causes crash, test needed
  ASSERT_STREQ( (wchar_t *)getCue( 0 ).id().text(), L"" );
  /**
   * We're expecting a WEBVTT_CUE_INCOMPLETE error on the 1st column of the 4th line
   */
  ASSERT_EQ( WEBVTT_CUE_INCOMPLETE, err.error() );
  ASSERT_EQ( 4, err.line() );
  ASSERT_EQ( 1, err.column() );
}

/**
 * Test if parser fails if there are less than two line endings (LF or CRLF) between 2 cues
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 41. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 43. If line contains the three-character substring "-->" (U+002D HYPHEN-MINUS, U+002D HYPHEN-MINUS, U+003E GREATER-THAN SIGN), then set the already collected line flag and jump to the step labeled cue text processing.
 */
TEST_F(CueIdLineEndings, MissingBetweenPayloadAndId) //This parses for eternity until program is stopped, no error available
{
  loadVtt( "cue-ids/lineendings/missing_between_payload_and_id.vtt", 2 );
  const Error &err = getError( 0 );
  /**
   * Parser doesn't care if there is a blank line before the first cue or comment.
   */
  // Doesn't work, causes crash, test needed
  ASSERT_STREQ( (wchar_t *)getCue( 1 ).id().text(), L"" );
  /**
   * We're expecting a WEBVTT_ID_TRUNCATED error on the 1st column of the 6th line
   */
  ASSERT_EQ( WEBVTT_ID_TRUNCATED, err.error() );
  ASSERT_EQ( 6, err.line() );
  ASSERT_EQ( 1, err.column() );
}

/**
 * Test to fail with a LF in the identifier.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 34. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue
 * 50. Bad cue: Discard cue.
 * 53. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 54. If line contains the three-character substring "-->" (U+002D HYPHEN-MINUS, U+002D HYPHEN-MINUS, U+003E GREATER-THAN SIGN), then set the already collected line flag and jump to the step labeled cue loop.
 */
TEST_F(CueIdLineEndings, TwoLinesLF)
{
  loadVtt( "cue-ids/lineendings/two_lines_lf.vtt", 1 );
  const Error &err = getError( 0 );
  /**
   * None of the identifier is used.
   */
  ASSERT_STREQ( (wchar_t *)getCue( 0 ).id().text(), L"" );
  /**
   * We're expecting a WEBVTT_CUE_INCOMPLETE error on the 1st column of the 4th line
   */
  ASSERT_EQ( WEBVTT_CUE_INCOMPLETE, err.error() );
  ASSERT_EQ( 4, err.line() );
  ASSERT_EQ( 1, err.column() );
}

/**
 * Test to fail with a CRLF in the identifier.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 34. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue
 * 50. Bad cue: Discard cue.
 * 53. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 54. If line contains the three-character substring "-->" (U+002D HYPHEN-MINUS, U+002D HYPHEN-MINUS, U+003E GREATER-THAN SIGN), then set the already collected line flag and jump to the step labeled cue loop.
 */
TEST_F(CueIdLineEndings, TwoLinesCRLF)
{
  loadVtt( "cue-ids/lineendings/two_lines_crlf.vtt", 1 );
  const Error &err = getError( 0 );
  /**
   * None of the identifier is used.
   */
  ASSERT_STREQ( (wchar_t *)getCue( 0 ).id().text(), L"" );
  /**
   * We're expecting a WEBVTT_CUE_INCOMPLETE error on the 1st column of the 4th line
   */
  ASSERT_EQ( WEBVTT_CUE_INCOMPLETE, err.error() );
  ASSERT_EQ( 4, err.line() );
  ASSERT_EQ( 1, err.column() );
}