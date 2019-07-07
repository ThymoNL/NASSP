

class DSENew : public e_object
{
	enum DSEState
	{
		STOPPED,			/// Tape is stopped
		STARTING_PLAY,		/// Tape is accelerating to play speed
		STARTING_RECORD,	/// Tape is accelerating to play speed
		SLOWING_RECORD,		/// Tape is slowing to record speed
		PLAYING,			/// Tape is playing
		RECORDING,			/// Tape is recording
		STOPPING,			/// Tape is stopping
	};

public:
	DSENew();
	virtual ~DSEnew();

	void Init(Saturn *vessel);	       // Initialization

	///
	/// \brief Tape motion indicator.
	///
	bool TapeMotion();

	///
	/// \brief Start tape playing.
	///
	void Play();

	///
	/// \brief Stop tape playing.
	///
	void Stop();

	///
	/// \brief Start tape recording.
	///
	void Record(bool hbr);

	///
	/// \brief Timestep processing.
	///
	void TimeStep(double simt, double simdt);

	void LoadState(char *line);
	void SaveState(FILEHANDLE scn);

protected:
	Saturn *sat;					    /// Ship we're installed in
	DSEChunk tape[tapeSize];			/// Simulated tape.
	double tapeSpeedInchesPerSecond;	/// Tape speed in inches per second.
	double desiredTapeSpeed;			/// Desired tape speed in inches per second.
	double tapeMotion;					/// Tape motion from 0.0 to 1.0.
	DSEState state;						/// Tape state.

	double lastEventTime;				/// Last event time.
};


