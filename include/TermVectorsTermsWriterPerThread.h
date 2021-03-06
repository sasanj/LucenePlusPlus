/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#ifndef TERMVECTORSTERMSWRITERPERTHREAD_H
#define TERMVECTORSTERMSWRITERPERTHREAD_H

#include "TermsHashConsumerPerThread.h"

namespace Lucene
{
    class TermVectorsTermsWriterPerThread : public TermsHashConsumerPerThread
    {
    public:
        TermVectorsTermsWriterPerThread(TermsHashPerThreadPtr termsHashPerThread, TermVectorsTermsWriterPtr termsWriter);
        virtual ~TermVectorsTermsWriterPerThread();
        
        LUCENE_CLASS(TermVectorsTermsWriterPerThread);
            
    public:
        TermVectorsTermsWriterWeakPtr _termsWriter;
        TermsHashPerThreadWeakPtr _termsHashPerThread;
        DocStateWeakPtr _docState;
        
        TermVectorsTermsWriterPerDocPtr doc;
        ByteSliceReaderPtr vectorSliceReader;
        Collection<UTF8ResultPtr> utf8Results;
        String lastVectorFieldName;
    
    public:
        virtual void startDocument();
        virtual DocWriterPtr finishDocument();
        virtual TermsHashConsumerPerFieldPtr addField(TermsHashPerFieldPtr termsHashPerField, FieldInfoPtr fieldInfo);
        virtual void abort();
        
        /// Called only by assert
        bool clearLastVectorFieldName();
        bool vectorFieldsInOrder(FieldInfoPtr fi);
    };
}

#endif
