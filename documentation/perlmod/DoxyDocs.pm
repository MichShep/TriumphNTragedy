$doxydocs=
{
  classes => [
    {
      name => 'ActionCard',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'ActionCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'countryA',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'countryB',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'letter',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'number',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        },
        {
          name => 'season',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'ActionCard'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'ActionCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'countryA',
                type => 'const string'
              },
              {
                declaration_name => 'countryB',
                type => 'const string'
              },
              {
                declaration_name => 'season',
                type => 'const Season'
              },
              {
                declaration_name => 'letter',
                type => 'const char'
              },
              {
                declaration_name => 'number',
                type => 'const int'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'countryA',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string'
          },
          {
            kind => 'variable',
            name => 'countryB',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string'
          },
          {
            kind => 'variable',
            name => 'season',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Season'
          },
          {
            kind => 'variable',
            name => 'letter',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'char'
          },
          {
            kind => 'variable',
            name => 'number',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'App',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'renderer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'App'
        },
        {
          name => 'screen',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'App'
        },
        {
          name => 'window',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'App'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'window',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Window *'
          },
          {
            kind => 'variable',
            name => 'renderer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Renderer *'
          },
          {
            kind => 'variable',
            name => 'screen',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Graphics::Screen'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'City',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'Map.h'
      },
      all_members => [
        {
          name => 'addUnit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'aggresor',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'City',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'City',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'city_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'color',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'country',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'freeMemory',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getEnemy',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getID',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'getName',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'HEIGHT',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'ID',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'influence',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'influencer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'isConflict',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'isEnemy',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'muster',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'name',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'numEnemies',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'occupants',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'population',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'power_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'printOccupants',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'removeUnit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'resource',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'resource_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'ruler_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'WIDTH',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'x',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        },
        {
          name => 'y',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'City'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'freeMemory',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'City',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new '
                },
                {
                  type => 'url',
                  link => 'struct_city',
                  content => 'City'
                },
                {
                  type => 'text',
                  content => ' object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'ID'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'id of the city '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Name of the city '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'city_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The starting allegiance of the city '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'power_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The power of the city (GREAT, HOME, MINOR, NONE) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'population'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The pop value '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'muster'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'How many troops are added when taken over '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'resource'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'How many resources given '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'resource_type'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The type of resource (N is none as well) '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'ID',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'name',
                type => 'const string',
                default_value => '"City"'
              },
              {
                declaration_name => 'city_type',
                type => 'const CityType',
                default_value => 'WATER'
              },
              {
                declaration_name => 'power_type',
                type => 'const PowerType',
                default_value => 'NONE'
              },
              {
                declaration_name => 'population',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'muster',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'resource',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'resource_type',
                type => 'const ResourceType',
                default_value => 'NORMAL'
              }
            ]
          },
          {
            kind => 'function',
            name => 'City',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'height',
                type => 'const int'
              },
              {
                declaration_name => 'width',
                type => 'const int'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'r',
                type => 'const int',
                default_value => '255'
              },
              {
                declaration_name => 'g',
                type => 'const int',
                default_value => '255'
              },
              {
                declaration_name => 'b',
                type => 'const int',
                default_value => '255'
              },
              {
                declaration_name => 'ID',
                type => 'const size_t',
                default_value => '0'
              },
              {
                declaration_name => 'name',
                type => 'const string',
                default_value => '"City"'
              }
            ]
          },
          {
            kind => 'function',
            name => 'isConflict',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If there currently a battle going on (more than one allegiance of troops) (Doesn\'t check neutrality) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true There is a battle '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false There is no battle (friendly troops or empty) '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'isEnemy',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Returns if the opposing troops are together. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance of the troop entering '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true There is enemies '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false No enemies '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'numEnemies',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Gives the number of enemies (not the number of units) in the current city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance of the unit '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t how many enemeis in the city depending on the unit\'s allegiance '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getEnemy',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'In the case where there is only one enemy return the one there. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance of the attacker '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'CityType The defender '
                    }
                  ]
                }
              ]
            },
            type => 'CityType',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'removeUnit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Removes a unit form this city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit to remove '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'addUnit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Adds a unit to this city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit to add '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'printOccupants',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getName',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getID',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Prints out all attributes of the city. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'HEIGHT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The height of the city when rendered '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'WIDTH',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The width of the city when rendered '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'x',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The x origin of the city shape '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'y',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The y origin of the city shape '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'color',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'ID',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The ID of the city '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'name',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The name of the city '
                }
              ]
            },
            type => 'string',
            initializer => '=""'
          },
          {
            kind => 'variable',
            name => 'country',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which larger country it belongs too '
                }
              ]
            },
            type => 'string',
            initializer => '=""'
          },
          {
            kind => 'variable',
            name => 'city_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'What type of power it starts as (West, Axis, Ussr) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'power_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Whats the power level of the city (great, home...) '
                }
              ]
            },
            type => 'PowerType'
          },
          {
            kind => 'variable',
            name => 'ruler_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current ruler of the city (origionally set to the city_type until conquered) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'population',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '< The population (pop) of the city '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'muster',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '< The muster determines how much troops are gained when influnced or strength of neutral forces when invaded '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'resource',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '< The amount of resources this city provides (mixed resources are always halfed so can be stored as one) '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'resource_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'ResourceType'
          },
          {
            kind => 'variable',
            name => 'occupants',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'What type of resource is on this city (only matters for blockades and going around Africa) Hold the current units and sperates them by their power 0:West, 1:Axis 2:USSR: 3:Neutral '
                }
              ]
            },
            type => 'vector< Unit * >',
            arguments => '[4]'
          },
          {
            kind => 'variable',
            name => 'influence',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The amount of influence on this country '
                }
              ]
            },
            type => 'uint8_t'
          },
          {
            kind => 'variable',
            name => 'influencer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The power who has the current influence over a starting neutral country (neutral if no influence) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'aggresor',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The Attacker is the Faction provoking Combat in that '
                },
                {
                  type => 'url',
                  link => 'class_player',
                  content => 'Player'
                },
                {
                  type => 'text',
                  content => ' Turn (the Active player). This is not the same as the Aggressor (the Faction trying to wrest control of a Land Area from the Owner) '
                }
              ]
            },
            type => 'CityType'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Each segment of the map where troops can be stationed. '
          }
        ]
      },
      detailed => {}
    },
    {
      name => 'Dice',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'Dice',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'Dice',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'max',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'min',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'roll',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        },
        {
          name => 'stats',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Dice'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Dice',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Dice',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'min',
                type => 'int'
              },
              {
                declaration_name => 'max',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'roll',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'stats',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Vector to hold how often each side was rolled '
                }
              ]
            },
            type => 'vector< int >'
          },
          {
            kind => 'variable',
            name => 'min',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Min calue of the die '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'max',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Max value of the die '
                }
              ]
            },
            type => 'int'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'InvestmentCard',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'amount',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'InvestmentCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'name',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'tech',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        },
        {
          name => 'year',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'InvestmentCard'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'InvestmentCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              },
              {
                declaration_name => 'tech',
                type => 'const Tech'
              },
              {
                declaration_name => 'amount',
                type => 'const int'
              },
              {
                declaration_name => 'year',
                type => 'const size_t'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'name',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string'
          },
          {
            kind => 'variable',
            name => 'tech',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Tech'
          },
          {
            kind => 'variable',
            name => 'amount',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'year',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Map',
      kind => 'class',
      inner => [
      ],
      all_members => [
        {
          name => 'addCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'adjacency',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'checkConnection',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'cities',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'city_masterlist',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Map'
        },
        {
          name => 'connect',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'findCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'freeMemory',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getAdjacency',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCities',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'getNumCity',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'initLists',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'operator[]',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'operator[]',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Map'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'initLists',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Initalizes the adjacency list. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'size'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The amount of cities and ultimate the side length of it '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'size',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'addCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Adds a city pointer to the map and master list. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The new city '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'city',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator[]',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'overloads [] such that the hash map can be accessed from outside the scope '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'target'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The name of the city that acts as the key '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* The city with the given name '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'target',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator[]',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Returns the city form the ML at the index (id) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'id'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The id of the target city '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* The city with the given id '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'id',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'connect',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Connects two cities with the given border and updates adjacncy list. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'idx1'
                        }
                      ],
                      doc => [
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'idx2'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'border'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'idx1',
                type => 'const size_t &'
              },
              {
                declaration_name => 'idx2',
                type => 'const size_t &'
              },
              {
                declaration_name => 'border',
                type => 'const BorderType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'findCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Works as the [] overload for out of scope but gives the ID of the found city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'City* '
                    },
                    {
                      type => 'url',
                      link => 'class_map_1ae1d96a7ee2becdc089361ea6d1403960',
                      content => 'operator[](const string target)'
                    }
                  ]
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'name of the desired city '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t the Id of the city with \'name\' '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Works as the [] overload for out of scope. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'City* '
                    },
                    {
                      type => 'url',
                      link => 'class_map_1ae1d96a7ee2becdc089361ea6d1403960',
                      content => 'operator[](const string target)'
                    }
                  ]
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'name of the desired city '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* The desired city obj '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the desiured city by id (works like [] overload) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'City* '
                    },
                    {
                      type => 'url',
                      link => 'class_map_1acc63b666965ca2606df11b94121aadfa',
                      content => 'operator[](const size_t id)'
                    }
                  ]
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'id'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'City* '
                    }
                  ]
                }
              ]
            },
            type => 'City *',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'id',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'checkConnection',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks to see if there is a connection between the two named cities. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'A'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Starting '
                        },
                        {
                          type => 'url',
                          link => 'struct_city',
                          content => 'City'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'B'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Ending '
                        },
                        {
                          type => 'url',
                          link => 'struct_city',
                          content => 'City'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true The cities share a connection '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false The cities don\'t share a connection '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'A',
                type => 'const string'
              },
              {
                declaration_name => 'B',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNumCity',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the total number of cities. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const size_t The total number of cities (shouldn\'t change after initalization) '
                    }
                  ]
                }
              ]
            },
            type => 'const size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getCities',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get reference to hash map of cities to reduce calls. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const unordered_map<string, City*>& The city hashmap reference '
                    }
                  ]
                }
              ]
            },
            type => 'const unordered_map< string, City * > &',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getAdjacency',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the adjacency matrix of cities to reduce calls. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'const vector<vector<BorderType>>& The adjacency matrix reference '
                    }
                  ]
                }
              ]
            },
            type => 'const vector< vector< BorderType > > &',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Prints all the cities and stats (not connections) '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'freeMemory',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Evokes each city to free memory before clearing the hasmap and masterlist. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'cities',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Hash table of all cities where the city pointer is the value of the '
                },
                {
                  type => 'url',
                  link => 'struct_city',
                  content => 'City'
                },
                {
                  type => 'text',
                  content => ' key name '
                }
              ]
            },
            type => 'unordered_map< string, City * >'
          },
          {
            kind => 'variable',
            name => 'city_masterlist',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Masterlist of all cities '
                }
              ]
            },
            type => 'vector< City * >'
          },
          {
            kind => 'variable',
            name => 'adjacency',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '< Is an adjacency matrix of the cities where the connection of cities is reresented by as nonzero value (0 is an offset city) '
                }
              ]
            },
            type => 'vector< vector< BorderType > >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Player',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'Player.h'
      },
      all_members => [
        {
          name => 'action_hand',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'allegiance',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'atomic',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'axis',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'axis_treaty',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'axisInit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'battles_lost',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'battles_won',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'card_size',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'cards_spent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'cities_controlled',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'factory_cost',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'getallegiance',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getHandSize',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getMaxCard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getMaxProduction',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getPopulation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getResource',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'getVP',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'industry',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'invest_hand',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'mapPlayer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'name',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'Player',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'Player',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'Player',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'population',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'resources',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'rival_capitals',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'setPopulation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'setResource',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'total_units',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'units',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'usa_treaty',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'ussr_treaty',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'ussrInit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        },
        {
          name => 'victory_points',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'west_treaty',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Player'
        },
        {
          name => 'westInit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Player'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Player',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Player',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              },
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Player',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'name',
                type => 'const string'
              },
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              },
              {
                declaration_name => 'population',
                type => 'const size_t'
              },
              {
                declaration_name => 'resource',
                type => 'const size_t'
              },
              {
                declaration_name => 'industry',
                type => 'const size_t'
              },
              {
                declaration_name => 'card_size',
                type => 'const size_t'
              },
              {
                declaration_name => 'factory_cost',
                type => 'const size_t'
              },
              {
                declaration_name => 'ussr_treaty',
                type => 'const bool'
              },
              {
                declaration_name => 'axis_treaty',
                type => 'bool'
              },
              {
                declaration_name => 'allies_treaty',
                type => 'bool'
              },
              {
                declaration_name => 'usa_treaty',
                type => 'const bool'
              }
            ]
          },
          {
            kind => 'function',
            name => 'westInit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Setup West player on default values in rules. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'axisInit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Setup Axis player on default values in rules. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'ussrInit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Setup USSR player on default values in rules. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'mapPlayer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Goes through the map and fills in the players stats. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getallegiance',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'CityType',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getPopulation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getResource',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setPopulation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'pop',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setResource',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'res',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHandSize',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getMaxCard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getMaxProduction',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getVP',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'name',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'string'
          },
          {
            kind => 'variable',
            name => 'victory_points',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'rival_capitals',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'atomic',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'allegiance',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'population',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'resources',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'industry',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'card_size',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'factory_cost',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'units',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'vector< Unit * >'
          },
          {
            kind => 'variable',
            name => 'ussr_treaty',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'west_treaty',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'axis_treaty',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'axis',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'usa_treaty',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'action_hand',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'vector< ActionCard * >'
          },
          {
            kind => 'variable',
            name => 'invest_hand',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'vector< InvestmentCard * >'
          },
          {
            kind => 'variable',
            name => 'battles_won',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Allies:0 Axis:1 USSR:2 where each index specifies against who '
                }
              ]
            },
            type => 'size_t',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'battles_lost',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Allies:0 Axis:1 USSR:2 where each index specifies against who '
                }
              ]
            },
            type => 'size_t',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'total_units',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Each index is a specific unit and how much '
                }
              ]
            },
            type => 'size_t',
            arguments => '[8]'
          },
          {
            kind => 'variable',
            name => 'cards_spent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'cities_controlled',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Represents Great Power and '
          },
          {
            type => 'url',
            link => 'class_player',
            content => 'Player'
          },
          {
            type => 'text',
            content => ' Stats. '
          }
        ]
      },
      detailed => {}
    },
    {
      name => 'Runner',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'Runner.h'
      },
      all_members => [
        {
          name => 'action_deck',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'action_discard',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'active_player',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'app',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'blockade',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'canDisengage',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'canMove',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'ClearScreen',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'combatRound',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'die',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'disengage',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'draw',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawAir',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawCarrier',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'DrawCity',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'DrawConnections',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawConvoy',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawFleet',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawFortress',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawInfantry',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawNumber',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawSub',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'drawTank',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'DrawTimeTrack',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'end_year',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'fall',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'freeMemory',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'getBattles',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'getMap',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'getNumPlayers',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'government',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'handCheck',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'InitApplication',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'initMap',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'InitSDL',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'invest_discard',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'invest_hand',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'landCombat',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'map',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'mapPlayer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'move',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'newNear',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'newYearRes',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'num_players',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'peaceDividends',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'players',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'printMemo',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'production',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'reshuffle',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'run',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'Runner',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'seaCombat',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'ShutdownApplication',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'spring',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'start_player',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        },
        {
          name => 'summer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'test',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'test1',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'winter',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Runner'
        },
        {
          name => 'year',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'Runner'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Runner',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new '
                },
                {
                  type => 'url',
                  link => 'class_runner',
                  content => 'Runner'
                },
                {
                  type => 'text',
                  content => ' object that intializes the map and players. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'default_mode'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'true if should go off of default or read in through the map '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'default_mode',
                type => 'bool',
                default_value => '1'
              }
            ]
          },
          {
            kind => 'function',
            name => 'test',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'test1',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'initMap',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Creates the game map including nations and cities and connections. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Was able to succesfully make the map '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Encountered an error while making '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'map_file',
                type => 'string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'run',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'newNear',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'CityType',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'production',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'government',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'spring',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'summer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'blockade',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'fall',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'winter',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'reshuffle',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'peaceDividends',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'newYearRes',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'handCheck',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'mapPlayer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Goes over the players holdings over the map and sums up their pop, res, CV. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'player'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true No changes were made from the stored attributes '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Changes were made from stale attributes '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'player',
                type => 'Player &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'move',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'start',
                type => 'const string'
              },
              {
                declaration_name => 'end',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'disengage',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When the unit is leaving a battle it can move to one adjacent friendly city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit disengaging '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'start'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city with the conflict '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'end'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The city to disengage to '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Is able to move to end '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false is unable (border limits or out of range or not friendly) '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'start',
                type => 'const string'
              },
              {
                declaration_name => 'end',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'canMove',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks if that unit is able to move into that city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit moving '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'name'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The target '
                        },
                        {
                          type => 'url',
                          link => 'struct_city',
                          content => 'City'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t How much movement would be left (returns INFI if it can\'t) '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'start',
                type => 'const string'
              },
              {
                declaration_name => 'name',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'combatRound',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Executes the current players combat rounds. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '!! Methods for combat round !!! '
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'landCombat',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Executes a land battle at the given city for one combat round. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'battlefield'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The city with the battle taken place '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'battlefield',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'seaCombat',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Executes a sea battle at the given \'city\' until concluded. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'battlefield'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The \'city\' with the battle taken place '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true if the combat round needs to repeat '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false if the battle fininshed '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'battlefield',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getBattles',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Check which cities have a current battle happening. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'allegiance'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The allegiance of the current player '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'vector<City*> Vector of all cities the player is batteling for '
                    }
                  ]
                }
              ]
            },
            type => 'vector< City * >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNumPlayers',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Get the number of players. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'size_t The number of playes in the game (2 or 3) '
                    }
                  ]
                }
              ]
            },
            type => 'size_t',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'freeMemory',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getMap',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const Map &',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'canDisengage',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'start',
                type => 'const string'
              },
              {
                declaration_name => 'end',
                type => 'const string'
              }
            ]
          },
          {
            kind => 'function',
            name => 'printMemo',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'memo',
                type => 'size_t',
                array => '[][5]'
              }
            ]
          },
          {
            kind => 'function',
            name => 'InitSDL',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '!! Graphics things '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Initalizes SDL2 and the window'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Initalized succesfully '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Failexcd to initalize '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'ClearScreen',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Clears the screen so the screen can \'update\'. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'ShutdownApplication',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Deletes the windows and frees memory specifically used by SDL. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'InitApplication',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Initalizes the \'app\', the struct that hlds the renderer and the window. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'true Initalized succesfully '
                    },
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'false Failexcd to initalize '
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'DrawCity',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws the city onto the renderer and the units that are in this city. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'city'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'city',
                type => 'City *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawFortress',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a fortress of the units nationality located at the given coords. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit thats a fortress '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The scale to draw the unit (origin is still x,y); scale of 1 is 5x5 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawAir',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a air unit of the units nationality located at the given coords. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit thats a air unit '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The scale to draw the unit (origin is still x,y); scale of 1 is 5x5 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawCarrier',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a carrier of the units nationality located at the given coords. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit thats a carrier '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The scale to draw the unit (origin is still x,y); scale of 1 is 5x5 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawSub',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a submarine unit of the units nationality located at the given coords. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit thats a sub '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The scale to draw the unit (origin is still x,y); scale of 1 is 5x5 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawFleet',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a fleet of the units nationality located at the given coords. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit thats a fleet '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The scale to draw the unit (origin is still x,y); scale of 1 is 5x5 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawTank',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a tank of the units nationality located at the given coords. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit thats a tank '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The scale to draw the unit (origin is still x,y); scale of 1 is 5x5 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawInfantry',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a infantry of the units nationality located at the given coords. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit thats a infantry '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The scale to draw the unit (origin is still x,y); scale of 1 is 5x5 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'drawConvoy',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws a conoy of the units nationality located at the given coords. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'unit'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'The unit thats a convoy '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The x coord of the unit (upper left corner is the origin) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The scale to draw the unit (origin is still x,y); scale of 1 is 5x5 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'unit',
                type => 'Unit *'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              }
            ]
          },
          {
            kind => 'function',
            name => 'DrawConnections',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws all the connections between the cities and colors them based on the border. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'DrawTimeTrack',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draws the current year and end year; shows the American flag and the level from 1941 to 1944. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'drawNumber',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Takes any length number and draws it as a 7-segment at the x,y as the top left. Origional scale is 7*13 for one digit. Defaul color is black. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'num'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Number to render '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'x'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'X coord of number origin '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'y'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Y coord of number origin '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'scale'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Scales draw size of the number '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'r'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The red value of the color (0, 255) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'g'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The green value of the color (0, 255) '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'b'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'The blue value of the color (0, 255) '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'num',
                type => 'const int'
              },
              {
                declaration_name => 'x',
                type => 'const int'
              },
              {
                declaration_name => 'y',
                type => 'const int'
              },
              {
                declaration_name => 'scale',
                type => 'const float'
              },
              {
                declaration_name => 'r',
                type => 'const uint8_t',
                default_value => '255'
              },
              {
                declaration_name => 'g',
                type => 'const uint8_t',
                default_value => '255'
              },
              {
                declaration_name => 'b',
                type => 'const uint8_t',
                default_value => '255'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'num_players',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Number of player in game (3 but hopefully can make a 1) '
                }
              ]
            },
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'players',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Player',
            arguments => '[3]'
          },
          {
            kind => 'variable',
            name => 'map',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Holds each playe object with allegiance as index 0: West 1: Axis 2: USSR '
                },
                {
                  type => 'url',
                  link => 'class_map',
                  content => 'Map'
                },
                {
                  type => 'text',
                  content => ' of the game and nations/waters '
                }
              ]
            },
            type => 'Map'
          },
          {
            kind => 'variable',
            name => 'year',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Current year the player is in (goes from 1936 to 1945) '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'end_year',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Year the game will end (usually 1945) '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'die',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'url',
                  link => 'struct_dice',
                  content => 'Dice'
                },
                {
                  type => 'text',
                  content => ' used to roll decisions, default a D6 '
                }
              ]
            },
            type => 'Dice'
          },
          {
            kind => 'variable',
            name => 'action_deck',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draw deck of the action cards '
                }
              ]
            },
            type => 'queue< ActionCard * >'
          },
          {
            kind => 'variable',
            name => 'action_discard',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draw deck of the action cards '
                }
              ]
            },
            type => 'vector< ActionCard * >'
          },
          {
            kind => 'variable',
            name => 'invest_hand',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Draw deck of the invest cards '
                }
              ]
            },
            type => 'queue< InvestmentCard * >'
          },
          {
            kind => 'variable',
            name => 'invest_discard',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Discard pile of investment cards '
                }
              ]
            },
            type => 'vector< InvestmentCard * >'
          },
          {
            kind => 'variable',
            name => 'start_player',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Player *'
          },
          {
            kind => 'variable',
            name => 'active_player',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'url',
                  link => 'class_player',
                  content => 'Player'
                },
                {
                  type => 'text',
                  content => ' who will start the turn '
                },
                {
                  type => 'url',
                  link => 'class_player',
                  content => 'Player'
                },
                {
                  type => 'text',
                  content => ' whose turn it is currently '
                }
              ]
            },
            type => 'Player *'
          },
          {
            kind => 'variable',
            name => 'app',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'App'
          },
          {
            kind => 'variable',
            name => 'draw',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'An array that holds the pointers to functions that draw the units, use4s the unit\'s type as an index. '
                }
              ]
            },
            detailed => {},
            type => 'void(Runner::*',
            arguments => '[8])(Unit *, int, int, float) const',
            initializer => '= {&Runner::drawFortress, &Runner::drawAir, &Runner::drawCarrier, &Runner::drawSub, &Runner::drawFleet, &Runner::drawTank, &Runner::drawInfantry, &Runner::drawConvoy}'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'The main controller of the game and controls sequence of play. '
          }
        ]
      },
      detailed => {}
    },
    {
      name => 'Graphics::Screen',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'center_x',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'center_y',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'HEIGHT',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        },
        {
          name => 'WIDTH',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Graphics::Screen'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'WIDTH',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            initializer => '= 1512'
          },
          {
            kind => 'variable',
            name => 'HEIGHT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            initializer => '= 982'
          },
          {
            kind => 'variable',
            name => 'center_x',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            initializer => '= WIDTH /2'
          },
          {
            kind => 'variable',
            name => 'center_y',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            initializer => '= HEIGHT /2'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Unit',
      kind => 'class',
      inner => [
      ],
      all_members => [
        {
          name => 'allegiance',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'class_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'combat_value',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'convoy',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'id',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'landing',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'max_combat_value',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'movement',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'nationality',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'print',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'rebase',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'setMovement',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'Unit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'Unit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        },
        {
          name => 'unit_type',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'Unit'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Unit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If the ground unit is a convoy its an infantry in the water and can\'t attack '
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'id',
                type => 'const size_t'
              },
              {
                declaration_name => 'nationality',
                type => 'UnitCountry'
              },
              {
                declaration_name => 'unit_type',
                type => 'UnitType'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Unit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'allegiance',
                type => 'const CityType'
              },
              {
                declaration_name => 'class_type',
                type => 'const UnitClass'
              },
              {
                declaration_name => 'unit_type',
                type => 'const UnitType'
              },
              {
                declaration_name => 'combat_value',
                type => 'const size_t'
              },
              {
                declaration_name => 'movement',
                type => 'const size_t'
              },
              {
                declaration_name => 'rebase',
                type => 'const bool'
              },
              {
                declaration_name => 'landing',
                type => 'const bool'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setMovement',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mov',
                type => 'const size_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'print',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'id',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'ID of the unit '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'allegiance',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which power the unit belongs to (West, Axis, USSR, Neutral) '
                }
              ]
            },
            type => 'CityType'
          },
          {
            kind => 'variable',
            name => 'nationality',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which country the unit comes from (West:British, USA, France; Axis: Germany, Italy; USSR: USSR) '
                }
              ]
            },
            type => 'UnitCountry'
          },
          {
            kind => 'variable',
            name => 'class_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which class the unit is in that is mostly just for movement and ReBase '
                }
              ]
            },
            type => 'UnitClass'
          },
          {
            kind => 'variable',
            name => 'unit_type',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Which type of unit that decied attack and movement (Fortress, Infantry, Air...) '
                }
              ]
            },
            type => 'UnitType'
          },
          {
            kind => 'variable',
            name => 'combat_value',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Functions as how many forces are in the one unit and how many it fires in battle '
                }
              ]
            },
            type => 'uint8_t'
          },
          {
            kind => 'variable',
            name => 'max_combat_value',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Limits the max amount offorces can be in the unit '
                }
              ]
            },
            type => 'uint8_t'
          },
          {
            kind => 'variable',
            name => 'movement',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The max amount of cities it can move in one turn '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'rebase',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'If this unit can ReBase (move freely to ground force) '
                }
              ]
            },
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'landing',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The year the unit landed from water this turn (therefore it can\'t attack) '
                }
              ]
            },
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'convoy',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  concepts => [
  ],
  modules => [
  ],
  namespaces => [
    {
      name => 'Colors',
      variables => {
        members => [
          {
            kind => 'variable',
            name => 'BLACK',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const SDL_Color',
            initializer => '= {0, 0, 0, 255}'
          },
          {
            kind => 'variable',
            name => 'GREEN',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const SDL_Color',
            initializer => '= {0, 255, 0, 255}'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Graphics',
      classes => [
        {
          name => 'Graphics::Screen'
        }
      ],
      brief => {},
      detailed => {}
    }
  ],
  files => [
    {
      name => 'Graphics.h',
      includes => [
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      included_by => [
        {
          name => 'main.cpp',
          ref => 'main_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Includes.h',
      includes => [
        {
          name => 'iostream'
        },
        {
          name => 'fstream'
        },
        {
          name => 'vector'
        },
        {
          name => 'unordered_map'
        },
        {
          name => 'cstdio'
        },
        {
          name => 'sstream'
        },
        {
          name => 'queue'
        },
        {
          name => 'cmath'
        },
        {
          name => '/opt/homebrew/Cellar/sdl2/2.30.2/include/SDL2/SDL.h'
        },
        {
          name => '/opt/homebrew/Cellar/sdl2_ttf/2.22.0/include/SDL2/SDL_ttf.h'
        }
      ],
      included_by => [
        {
          name => 'Unit.h',
          ref => '_unit_8h'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'END_YEAR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '1945;'
          },
          {
            kind => 'define',
            name => 'START_YEAR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '1936;'
          },
          {
            kind => 'define',
            name => 'INFI',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => 'SIZE_MAX;'
          }
        ]
      },
      enums => {
        members => [
          {
            kind => 'enum',
            name => 'CityType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'WEST',
                brief => {},
                detailed => {}
              },
              {
                name => 'AXIS',
                brief => {},
                detailed => {}
              },
              {
                name => 'USSR',
                brief => {},
                detailed => {}
              },
              {
                name => 'NEUTRAL',
                brief => {},
                detailed => {}
              },
              {
                name => 'NEUTRAL_AT_WAR',
                brief => {},
                detailed => {}
              },
              {
                name => 'WATER',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'PowerType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'GREAT',
                brief => {},
                detailed => {}
              },
              {
                name => 'HOME',
                brief => {},
                detailed => {}
              },
              {
                name => 'MINOR',
                brief => {},
                detailed => {}
              },
              {
                name => 'NONE',
                brief => {},
                detailed => {}
              },
              {
                name => 'SEA',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'ResourceType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NORMAL',
                brief => {},
                detailed => {}
              },
              {
                name => 'TRANS_ATLANTIC',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'BorderType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NA',
                brief => {},
                detailed => {}
              },
              {
                name => 'COAST',
                brief => {},
                detailed => {}
              },
              {
                name => 'STRAIT',
                brief => {},
                detailed => {}
              },
              {
                name => 'MOUNTAIN',
                brief => {},
                detailed => {}
              },
              {
                name => 'FOREST',
                brief => {},
                detailed => {}
              },
              {
                name => 'RIVER',
                brief => {},
                detailed => {}
              },
              {
                name => 'PLAINS',
                brief => {},
                detailed => {}
              },
              {
                name => 'OCEAN',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'UnitClass',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'CLASS_A',
                brief => {},
                detailed => {}
              },
              {
                name => 'CLASS_N',
                brief => {},
                detailed => {}
              },
              {
                name => 'CLASS_G',
                brief => {},
                detailed => {}
              },
              {
                name => 'CLASS_S',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'UnitType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'FORTRESS',
                brief => {},
                detailed => {}
              },
              {
                name => 'AIR',
                brief => {},
                detailed => {}
              },
              {
                name => 'CARRIER',
                brief => {},
                detailed => {}
              },
              {
                name => 'SUB',
                brief => {},
                detailed => {}
              },
              {
                name => 'FLEET',
                brief => {},
                detailed => {}
              },
              {
                name => 'TANK',
                brief => {},
                detailed => {}
              },
              {
                name => 'INFANTRY',
                brief => {},
                detailed => {}
              },
              {
                name => 'CONVOY',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'UnitCountry',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'BRITIAN_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'FRANCE_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'USA_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'GERMANY_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'ITALY_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'USSR_U',
                brief => {},
                detailed => {}
              },
              {
                name => 'NEUTRAL_U',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'Season',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'SPRING',
                brief => {},
                detailed => {}
              },
              {
                name => 'SUMMER',
                brief => {},
                detailed => {}
              },
              {
                name => 'FALL',
                brief => {},
                detailed => {}
              },
              {
                name => 'WINTER',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'Tech',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'AIR_DEFENSE',
                brief => {},
                detailed => {}
              },
              {
                name => 'FIRST_FIRE',
                brief => {},
                detailed => {}
              },
              {
                name => 'INDUSTRIAL_ESPIONAGE',
                brief => {},
                detailed => {}
              },
              {
                name => 'SCIENCE',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      variables => {
        members => [
          {
            kind => 'variable',
            name => 'FIREPOWER_TABLE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[8][4]',
            initializer => '= { 
    {2, 3, 4, 3}, 
    {3, 1, 1, 1}, 
    {2, 2, 1, 2}, 
    {2, 2, 1, 2}, 
    {1, 3, 1, 2}, 
    {0, 0, 2, 0}, 
    {1, 1, 3, 0}, 
    {0, 0, 0, 0}  
}'
          },
          {
            kind => 'variable',
            name => 'MAX_CV_TABLE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[8][7]',
            initializer => '= { 
    {4, 3, 4, 4, 3, 3, 3}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {4, 3, 4, 4, 3, 3, 0}, 
    {0, 0, 0, 0, 0, 3, 0}  
}'
          },
          {
            kind => 'variable',
            name => 'COLOR_TABLE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const Uint8',
            arguments => '[6][3]',
            initializer => '= {
    {16, 28, 238}, 
    {142, 143, 158}, 
    {210, 13, 13}, 
    {251, 160, 6}, 
    {233, 99, 6}, 
    {131, 236, 232}  
}'
          },
          {
            kind => 'variable',
            name => 'BORDER_COLOR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[8][3]',
            initializer => '{
    {0,0,0}, 
    {0,198,226}, 
    {9,132,149}, 
    {61,63,63}, 
    {25,198,27}, 
    {159, 244, 255}, 
    {221, 239, 198}, 
    {131, 236, 232} 
}'
          },
          {
            kind => 'variable',
            name => 'UNIT_COLOR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const int',
            arguments => '[7][3]',
            initializer => '{ 
    {11, 56, 208}, 
    {36, 226, 208}, 
    {42, 171, 85}, 
    {178, 191, 196}, 
    {210, 200, 128}, 
    {213, 19, 19}, 
    {255, 191, 58} 
}'
          },
          {
            kind => 'variable',
            name => 'SEVEN_SEGMENT_DISPLAY',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const bool',
            arguments => '[10][7]',
            initializer => '= { 
    { 1,1,1,1,1,1,0 }, 
    { 0,1,1,0,0,0,0 }, 
    { 1,1,0,1,1,0,1 }, 
    { 1,1,1,1,0,0,1 }, 
    { 0,1,1,0,0,1,1 }, 
    { 1,0,1,1,0,1,1 }, 
    { 1,0,1,1,1,1,1 }, 
    { 1,1,1,0,0,0,0 }, 
    { 1,1,1,1,1,1,1 }, 
    { 1,1,1,0,0,1,1 }  
}'
          },
          {
            kind => 'variable',
            name => 'BLACK',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const SDL_Color',
            initializer => '= {0, 0, 0, 255}'
          },
          {
            kind => 'variable',
            name => 'GREEN',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const SDL_Color',
            initializer => '= {0, 255, 0, 255}'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'main.cpp',
      includes => [
        {
          name => 'Graphics.h',
          ref => '_graphics_8h'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'SDL_MAIN_HANDELED',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          }
        ]
      },
      functions => {
        members => [
          {
            kind => 'function',
            name => 'main',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'argc',
                type => 'int'
              },
              {
                declaration_name => 'argv',
                type => 'char *',
                array => '[]'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'Map.cpp',
      includes => [
        {
          name => 'Map.h',
          ref => '_map_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Map.h',
      includes => [
        {
          name => 'Unit.h',
          ref => '_unit_8h'
        }
      ],
      included_by => [
        {
          name => 'Map.cpp',
          ref => '_map_8cpp'
        },
        {
          name => 'Player.h',
          ref => '_player_8h'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Player.cpp',
      includes => [
        {
          name => 'Player.h',
          ref => '_player_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Player.h',
      includes => [
        {
          name => 'Map.h',
          ref => '_map_8h'
        }
      ],
      included_by => [
        {
          name => 'Player.cpp',
          ref => '_player_8cpp'
        },
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Runner.cpp',
      includes => [
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Runner.h',
      includes => [
        {
          name => 'Player.h',
          ref => '_player_8h'
        }
      ],
      included_by => [
        {
          name => 'Graphics.h',
          ref => '_graphics_8h'
        },
        {
          name => 'Runner.cpp',
          ref => '_runner_8cpp'
        },
        {
          name => 'Sequence.cpp',
          ref => '_sequence_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Sequence.cpp',
      includes => [
        {
          name => 'Runner.h',
          ref => '_runner_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Unit.cpp',
      includes => [
        {
          name => 'Unit.h',
          ref => '_unit_8h'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'Unit.h',
      includes => [
        {
          name => 'Includes.h',
          ref => '_includes_8h'
        }
      ],
      included_by => [
        {
          name => 'Map.h',
          ref => '_map_8h'
        },
        {
          name => 'Unit.cpp',
          ref => '_unit_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    }
  ],
  groups => [
  ],
  pages => [
  ]
};
1;
