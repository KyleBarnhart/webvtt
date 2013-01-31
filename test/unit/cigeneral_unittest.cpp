#include "cue_testfixture"
class CueIdGeneral : public CueTest { };

/**
 * Test to determine if the most basic one-character cue id passes
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 18. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 31. Let cue's text track cue identifier be line.
 */
TEST_F(CueIdGeneral, BasicPass) //C++ exception: "std::bad_alloc"
{
  loadVtt( "cue-ids/basic_pass.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  // Doesn't work, causes crash, test needed
  ASSERT_STREQ( (wchar_t *)getCue( 0 ).id().text(), L"1" );
}

/**
 * Test to determine if a WEBVTT Cue Id allows a *very* large character input.
 * This test floods the cue ID with characters, but should pass
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 18. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 31. Let cue's text track cue identifier be line.
 */
TEST_F(CueIdGeneral, LongString) //Test currently throws a webvtt cue incomplete error, however it should pass
{
  loadVtt( "cue-ids/long_string.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  // Doesn't work, causes crash, test needed
  ASSERT_STREQ( (wchar_t *)getCue( 0 ).id().text(), L"The Survey-Ship Tethys made the first landing on the planet, which had no name. It was an admirable planet in many ways. It had an ample atmosphere and many seas, which the nearby sun warmed so lavishly that a perpetual cloud-bank hid them and most of the solid ground from view. It had mountains and continents and islands and high plateaus. It had day and night and wind and rain, and its mean temperature was within the range to which human beings could readily accommodate. It was rather on the tropic side, but not unpleasant. But there was no life on it. No animals roamed its continents. No vegetation grew from its rocks. Not even bacteria struggled with its stones to turn them into soil. So there was no soil. Rock and stones and gravel and even sand--yes. But no soil in which any vegetation could grow. No living thing, however small, swam in its oceans, so there was not even mud on its ocean-bottoms. It was one of that disappointing vast majority of worlds which turned up when the Galaxy was first explored. People couldn\'t live on it because nothing had lived there before. Its water was fresh and its oceans were harmless. Its air was germ-free and breathable. But it was of no use whatever for men. The only possible purpose it could serve would have been as a biological laboratory for experiments involving things growing in a germ-free environment. But there were too many planets like that already. When men first traveled to the stars they made the journey because it was starkly necessary to find new worlds for men to live on. Earth was over-crowded--terribly so. So men looked for new worlds to move to. They found plenty of new worlds, but presently they were searching desperately for new worlds where life had preceded them. It didn\'t matter whether the life was meek and harmless, or ferocious and deadly. If life of any sort were present, human beings could move in. But highly organized beings like men could not live where there was no other life. So the Survey-Ship Tethys made sure that the world had no life upon it. Then it made routine measurements of the gravitational constant and the magnetic field and the temperature gradient; it took samples of the air and water. But that was all. The rocks were familiar enough. No novelties there! But the planet was simply useless. The survey-ship put its findings on a punched card, six inches by eight, and went hastily on in search of something better. The ship did not even open one of its ports while on the planet. There were no consequences of the Tethys\' visit except that card. None whatever. No other ship came near the planet for eight hundred years. Nearly a millenium later, however, the Seed-Ship Orana arrived. By that time humanity had spread very widely and very far. There were colonies not less than a quarter of the way to the Galaxy\'s rim, and Earth was no longer over-crowded. There was still emigration, but it was now a trickle instead of the swarming flood of centuries before. Some of the first-colonized worlds had emigrants, now. Mankind did not want to crowd itself together again! Men now considered that there was no excuse for such monstrous slums as overcrowding produced. Now, too, the star-ships were faster. A hundred light-years was a short journey. A thousand was not impractical. Explorers had gone many times farther, and reported worlds still waiting for mankind on beyond. But still the great majority of discovered planets did not contain life. Whole solar systems floated in space with no single living cell on any of their members. So the Seed-Ships came into being. Theirs was not a glamorous service. They merely methodically contaminated the sterile worlds with life. The Seed-Ship Orana landed on this planet--which still had no name. It carefully infected it. It circled endlessly above the clouds, dribbling out a fine dust,--the spores of every conceivable microorganism which could break down rock to powder, and turn that dust to soil. It was also a seeding of moulds and fungi and lichens, and everything which could turn powdery primitive soil into stuff on which higher forms of life could grow. The Orana polluted the seas with plankton. Then it, too, went away. More centuries passed. Human ships again improved. A thousand light-years became a short journey. Explorers reached the Galaxy\'s very edge, and looked estimatingly across the emptiness toward other island universes. There were colonies in the Milky Way. There were freight-lines between star-clusters, and the commercial center of human affairs shifted some hundreds of parsecs toward the Rim. There were many worlds where the schools painstakingly taught the children what Earth was, and where, and that all other worlds had been populated from it. And the schools repeated, too, the one lesson that humankind seemed genuinely to have learned. That the secret of peace is freedom, and the secret of freedom is to be able to move away from people with whom you do not agree. There were no crowded worlds any more. But human beings love children, and they have them. And children grow up and need room. So more worlds had to be looked out for. They weren\'t urgently needed yet, but they would be. Therefore, nearly a thousand years after the Orana, the Ecology-Ship Ludred swam to the planet from space and landed on it. It was a gigantic ship of highly improbable purpose. First of all, it checked on the consequences of the Orana\'s visit. They were highly satisfactory, from a technical point of view. Now there was soil which swarmed with minute living things. There were fungi which throve monstrously. The seas stank of minuscule life-forms. There were even some novelties, developed by the strictly local conditions. There were, for example, paramoecia as big as grapes, and yeasts had increased in size until they bore flowers visible to the naked eye. The life on the planet was not aboriginal, though. All of it was descended and adapted and modified from the microorganisms planted by the seed-ship whose hulk was long since rust, and whose crew were merely names in genealogies--if that. The Ludred stayed on the planet a considerably longer time than either of the ships that had visited it before. It dropped the seeds of plants. It broadcast innumerable varieties of things which should take root and grow. In some places it deliberately seeded the stinking soil. It put marine plants in the oceans. It put alpine plants on the high ground. And when all its stable varieties were set out it added plants which were genetically unstable. For generations to come they would throw sports, some of which should be especially suited to this planetary environment. Before it left, the Ludred dumped finny fish into the seas. At first they would live on the plankton which made the oceans almost broth. There were many varieties of fish. Some would multiply swiftly while small; others would grow and feed on the smaller varieties. And as a last activity, the Ludred set up refrigeration-units loaded with insect-eggs. Some would release their contents as soon as plants had grown enough to furnish them with food. Others would allow their contents to hatch only after certain other varieties had multiplied--to be their food-supply. When the Ecology-Ship left, it had done a very painstaking job. It had treated the planet to a sort of Russell\'s Mixture of life-forms. The real Russell\'s Mixture is that blend of the simple elements in the proportions found in suns. This was a blend of life-forms in which some should survive by consuming the now-habituated flora, others by preying on the former. The planet was stocked, in effect, with everything that it could be hoped would live there. But only certain things could have that hope. Nothing which needed parental care had any chance of survival. The creatures seeded at this time had to be those which could care for themselves from the instant they burst their eggs. So there were no birds or mammals. Trees and plants of many kinds, fish and crustaceans and tadpoles, and all kinds of insects could be planted. But nothing else. The Ludred swam away through emptiness. There should have been another planting centuries later. There should have been a ship from the Zoological Branch of the Ecological Service. It should have landed birds and beasts and reptiles. It should have added pelagic mammals to the seas. There should have been herbivorous animals to live on the grasses and plants which would have thriven, and carnivorous animals to live on them in turn. There should have been careful stocking of the planet with animal life, and repeated visits at intervals of a century or so to make sure that a true ecological balance had been established. And then when the balance was fixed men would come and destroy it for their own benefit. But there was an accident. Ships had improved again. Even small private space-craft now journeyed tens of light-years on holiday journeys. Personal cruisers traveled hundreds. Liners ran matter-of-factly on ship-lines tens of thousands of light-years long. An exploring-ship was on its way to a second island universe. (It did not come back.) The inhabited planets were all members of a tenuous organization which limited itself to affairs of space, without attempting to interfere in surface matters. That tenuous organization moved the Ecological Preparation Service files to Algol IV as a matter of convenience. In the moving, a card-file was upset. The cards it contained were picked up and replaced, but one was missed. It was not picked up. It was left behind. So the planet which had no name was forgotten. No other ship came to prepare it for ultimate human occupancy. It circled its sun, unheeded and unthought-of. Cloud-banks covered it from pole to pole. There were hazy markings in some places, where high plateaus penetrated its clouds. But that was all. From space the planet was essentially featureless. Seen from afar it was merely a round white ball--white from its cloud-banks--and nothing else. But on its surface, on its lowlands, it was pure nightmare. But this fact did not matter for a very long time. Ultimately, it mattered a great deal--to the crew of the space-liner Icarus. The Icarus was a splendid ship of its time. It bore passengers headed for one of the Galaxy\'s spiral arms, and it cut across the normal lanes and headed through charted but unvisited parts of the Galaxy toward its destination. And it had one of the very, very, very few accidents known to happen to space-craft licensed for travel off the normal space-lanes. It suffered shipwreck in space, and its passengers and crew were forced to take to the life-craft. The lifeboats\' range was limited. They landed on the planet that the Tethys had first examined, that the Orana and the Ludred had seeded, and of which there was no longer any record in the card-files of the Ecological Service. Their fuel was exhausted. They could not leave. They could not signal for help. They had to stay there. And the planet was a place of nightmares. After a time the few people--some few thousands--who knew that there was a space-liner named Icarus, gave it up for lost. They forgot about it. Everybody forgot. Even the passengers and crew of the ship forgot it. Not immediately, of course. For the first few generations their descendants cherished hopes of rescue. But the planet which had no name--the forgotten planet--did not encourage the cherishing of hope. After forty-odd generations, nobody remembered the Icarus anywhere. The wreckage of the lifeboats was long since hidden under the seething, furiously striving fungi of the soil. The human beings had forgotten not only their ancestors\' ship, but very nearly everything their ancestors had brought to this world: the use of metals, the existence of fire, and even the fact that there was such a thing as sunshine. They lived in the lowlands, deep under the cloud-bank, amid surroundings which were riotous, swarming, frenzied horror. They had become savages. They were less than savages, because they had forgotten their destiny as men." );
}

/**
 * Test if parser fails if the webvtt file only has a cue id (no timestamp or payload)
 * and it is not a NOTE
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 18. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 32. If position is past the end of input, then discard cue and jump to the step labeled end.
 */
TEST_F(CueIdGeneral, IdOnly)
{
  loadVtt( "cue-ids/id_only.vtt", 0 );
  const Error &err = getError( 0 );
  /**
   * We're expecting a WEBVTT_CUE_INCOMPLETE error on the 2nd column of the 3rd line
   */
  ASSERT_EQ( WEBVTT_CUE_INCOMPLETE, err.error() );
  ASSERT_EQ( 3, err.line() );
  ASSERT_EQ( 2, err.column() );
}

/**
 * Test if parser fails if the webvtt file only has a cue id (no timestamp or payload)
 * and it is not a NOTE
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 34. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 35. If line is the empty string, then discard cue and jump to the step labeled cue loop.
 */
TEST_F(CueIdGeneral, IdOnlyTrailingNewline)
{
  loadVtt( "cue-ids/id_only_trailing_newline.vtt", 0 );
  const Error &err = getError( 0 );
  /**
   * We're expecting a WEBVTT_CUE_INCOMPLETE error on the 0 column of the 8th line
   */
  ASSERT_EQ( WEBVTT_CUE_INCOMPLETE, err.error() );
  ASSERT_EQ( 8, err.line() );
  ASSERT_EQ( 0, err.column() );
}

/**
 * Test that null characters are replaced by replacement characters.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (12/13/2012)
 * 1. Let input be the string being parsed, after conversion to Unicode, and with the following transformations applied:
 * Replace all U+0000 NULL characters by U+FFFD REPLACEMENT CHARACTERs.
 */
TEST_F(CueIdGeneral, Null)
{
  loadVtt( "cue-ids/null.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";

  // Doesn't work, causes crash, test needed
  ASSERT_STREQ( (wchar_t *)getCue( 0 ).id().text(), L"\uFFFD");
}
