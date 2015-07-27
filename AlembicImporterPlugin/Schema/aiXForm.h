#ifndef aiXForm_h
#define aiXForm_h

class aiXFormSample : public aiSampleBase
{
typedef aiSampleBase super;
public:
    aiXFormSample(aiXForm *schema, float time);

    void updateConfig(const aiConfig &config, bool &topoChanged, bool &dataChanged) override;

    void getData(aiXFormData &outData) const;

public:
    AbcGeom::XformSample m_sample;
};


struct aiXFormTraits
{
    typedef aiXFormSample SampleT;
    typedef AbcGeom::IXformSchema AbcSchemaT;
};

class aiXForm : public aiTSchema<aiXFormTraits>
{
typedef aiTSchema<aiXFormTraits> super;
public:
    aiXForm(aiObject *obj);

    Sample* readSample(float time) override;
};

#endif
