#ifndef _DefaultTrimmedVertexFinder_H_
#define _DefaultTrimmedVertexFinder_H_

#include "RecoVertex/TrimmedKalmanVertexFinder/interface/ConfigurableTrimmedVertexFinder.h"

/** User-friendly wrapper around TrimmedVertexFinder. <BR>
 *  Chooses the KalmanVertexFit classes as vertex fitting classes 
 *  used by the TrimmedVertexFinder. <BR>
 *  DefaultTrimmedVertexFinder is configurable 
 *  using the same set() methods as TrimmedVertexFinder. 
 */

class DefaultTrimmedVertexFinder 
  : public VertexReconstructor {

public:

  DefaultTrimmedVertexFinder();
  DefaultTrimmedVertexFinder(
    const DefaultTrimmedVertexFinder & other);
  virtual ~DefaultTrimmedVertexFinder();

  /** Clone method
   */
  virtual DefaultTrimmedVertexFinder * clone() const {
    return new DefaultTrimmedVertexFinder(*this);
  }

  virtual inline vector<RecVertex> vertices(const vector<RecTrack> & tracks)
    const { return theFinder->vertices(tracks); }

  inline vector<RecVertex> vertices( const vector<RecTrack> & tracks,
				     vector<RecTrack>& unused) const {
    return theFinder->vertices(tracks, unused);
  }

  /** Access to parameters
   */
  inline float ptCut() const { return theFinder->ptCut(); }
  inline float trackCompatibilityCut() const { 
    return theFinder->trackCompatibilityCut();
  }
  inline float trackCompatibilityToSV() const { 
    return theFinder->trackCompatibilityToSV();
  }
  inline float vertexFitProbabilityCut() const { 
    return theFinder->vertexFitProbabilityCut();
  }
  inline int maxNbOfVertices() const { return theFinder->maxNbOfVertices(); }

  /** Set parameters
   */
  inline void setPtCut(float cut) { theFinder->setPtCut(cut); }
  inline void setTrackCompatibilityCut(float cut) {
    theFinder->setTrackCompatibilityCut(cut);
  }
  inline void setTrackCompatibilityToSV(float cut) {
    theFinder->setTrackCompatibilityToSV(cut);
  }
  inline void setVertexFitProbabilityCut(float cut) { 
    theFinder->setVertexFitProbabilityCut(cut);
  }
  inline void setMaxNbOfVertices(int max) { 
    theFinder->setMaxNbOfVertices(max);
  }

private:

  ConfigurableTrimmedVertexFinder * theFinder;

};

#endif